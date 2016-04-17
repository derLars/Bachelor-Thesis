#ifndef SRC_FACTORY_H_
#define SRC_FACTORY_H_

#include <memory>
#include <unordered_map>

using namespace std;

template<typename Super>
class Factory {
    class Cloner {
    public:
        virtual shared_ptr<Super> clone() const = 0;
        const int idx;
        virtual ~Cloner() {}
    protected:
        Cloner(int idx) :
            idx(idx) {}
    };

    template<typename T>
    class ClonerT: public Cloner {
    public:
        ClonerT() {}

        ClonerT(int idx, const T& obj) :
            Cloner(idx), obj_(obj) {}

    private:
        virtual shared_ptr<Super> clone() const {
            return make_shared<T>(obj_);
        }
        const T obj_;
    };

public:
    template<typename T>
    void add(int idx, const T& obj) {
        cloneMap.emplace(idx, make_unique<ClonerT<T>>(idx, obj));
    }

    shared_ptr<Super> getInstance(int idx) const {
        auto foundEntry = cloneMap.find(idx);

        if (foundEntry == cloneMap.end()) {
            return nullptr;
        }
        return shared_ptr<Super>((foundEntry->second)->clone());
    }

private:
    unordered_map<int, unique_ptr<Cloner>> cloneMap;
};

#endif /* SRC_FACTORY_H_ */
