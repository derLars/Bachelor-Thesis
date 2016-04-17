#include "State.h"

class Off : public State{
public:
    Off(weak_ptr<Context> context): State(context) {
    }

    virtual void on();
    virtual void off();
    virtual void destroy();
    virtual void status();

    ~Off(){};
};
