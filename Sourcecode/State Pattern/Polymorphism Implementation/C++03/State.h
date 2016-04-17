#ifndef SRC_STATE_H_
#define SRC_STATE_H_

#include <iostream>
#include <memory>
using namespace std;

class Context;

class State {
public:
    enum INPUT{ON=0,OFF=1,DESTROY=2};

    State(){context = 0; }
    State(Context* context){this->context = context;}
    
    virtual ~State(){};
    
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void destroy() = 0;
    virtual void status() = 0;

    Context* context;
};

#endif //SRC_STATE_H
