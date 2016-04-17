#ifndef SRC_CONTEXT_H_
#define SRC_CONTEXT_H_

#include "State.h"

#include <map>

class Context : State {
public:
    enum SIGNAL{ON=0, OFF=1, DESTROY=2};

    Context();/* {
        numOfChanges = 0;
        state = new On(this);
        

        functionMap[ON]        	= &Context::on;
        functionMap[OFF] 		= &Context::off;
        functionMap[DESTROY]	= &Context::destroy;
    }*/

    ~Context();/* {
        delete state;
    }*/

    void input(int signal);/* {
        if(functionMap.find(signal) != functionMap.end()) {
            (this->*functionMap[signal])();
        }
    }*/

    void on();// {state->on();}
    void off();// {state->off();}
    void destroy();// {state->destroy();}

    void status();// {state->status();}

    State* state;

    int numOfChanges;

    std::map<int, void (Context::*) ()> functionMap;
};

#endif /* SRC_CONTEXT_H_ */
