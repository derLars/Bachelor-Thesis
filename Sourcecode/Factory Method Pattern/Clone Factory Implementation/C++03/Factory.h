#ifndef SRC_FACTORY_H_
#define SRC_FACTORY_H_

#include <vector>

using namespace std;

template<class Base>
class Factory {

    class Cloner {
    public:
        virtual Base* clone() const = 0;
        const int idx;
        virtual ~Cloner() {}
    protected:
        Cloner(int idx) :
        idx(idx) {}
    };

    template<class T>
    class ClonerT: public Cloner {
    public:
        ClonerT(const int idx, const T& obj) :
        Cloner(idx), obj_(obj) {}
        ~ClonerT(){}

    private:
        virtual Base* clone() const {
            return new T(obj_);
        }
        const T obj_;
    };

public:
    ~Factory() {
        for(unsigned int i=0; i<cloneList.size(); i++) {
            delete cloneList[i];
        }
    }

    template<class T>
    void add(const int idx, const T& obj) {
        cloneList.push_back(new ClonerT<T>(idx, obj));
    }

    Base* getInstance(const int idx) const {
        for(unsigned int i=0; i<cloneList.size(); i++) {
            if(cloneList[i]->idx == idx) {
                return cloneList[i]->clone();
            }
        }
        return 0;
    }
private:
    vector<Cloner*> cloneList;
};

#endif /* SRC_FACTORY_H_ */
