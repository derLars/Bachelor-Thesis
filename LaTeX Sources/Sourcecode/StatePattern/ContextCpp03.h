#include "LightOff.h"
#include <map>

using namespace std;
class Context : State {
public:
    enum SIGNAL{ON=0, OFF=1, DESTROY=2};
    
    Context() {
        numOfChanges = 0;
        state = new LightOff(this);
        
        functionMap[ON] = &Context::on;
        functionMap[OFF] = &Context::off;
        functionMap[DESTROY] = &Context::destroy;
    }

    void call(int signal) {
        if(functionMap.find(signal) != functionMap.end()) {
            (this->*functionMap[signal])();
        }
    }
    
    void on() {state->on();}
    void off() {state->off();}
    void destroy() {state->destroy();}
    void status() {state->status();}
	
    State* state;
    int numOfChanges;
private:
    map<int, void (Light::*) ()> functionMap;
};