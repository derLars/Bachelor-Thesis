#include "State.h"

class Destroyed : public State{
public:
    Destroyed(weak_ptr<Context> context): State(context) {
    }

    virtual void on();
    virtual void off();
    virtual void destroy();
    virtual void status();

    ~Destroyed(){};
};
