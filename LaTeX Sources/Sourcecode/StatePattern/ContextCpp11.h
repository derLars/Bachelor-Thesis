#include "State.h"
#include <unordered_map>

using namespace std;
class Context {
public:
    enum SIGNAL{ON=0, OFF=1, DESTROY=2};

    Context() {
        numOfChanges = 0;
    }

    void initialize(weak_ptr<Context> context) {
        state = make_unique<On>(context);

        functionMap.emplace(make_pair(ON, 
                            bind(&Context::on, this)));
        functionMap.emplace(make_pair(OFF, 
                            bind(&Context::off, this)));
        functionMap.emplace(make_pair(DESTROY, 
                            bind(&Context::destroy, this)));
    }

    void call(int signal) {
        auto found = functionMap.find(signal);
        if (found != functionMap.end()) {
            (found->second)();
        }
    }

    void on() {state->on();}
    void off() {state->off();}
    void destroy() {state->destroy();}
    void status() {state->status();}

    unique_ptr<State> state;
    int numOfChanges;
private:
    unordered_map<int, function<void()>> functionMap;
};
