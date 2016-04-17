#include <memory>
#include <unordered_map>
#include <functional>

using namespace std;

template<typename Base>
class LambdaFactory {
public:
    LambdaFactory() {
    }

    shared_ptr<Base> getInstance(const int idx) {
        auto found = lambdaMap.find(idx);
        return found != lambdaMap.end() ? found->second() : nullptr;  
    }

    template<size_t IDX, typename T, typename... Args>
    void add(Args... args) {
        lambdaMap.emplace(IDX,
            ([=]()-> auto {return make_shared<T>(args...);}));
    }

private:
    unordered_map<int,function<shared_ptr<Base>()>> lambdaMap;
};