#include "State.h"

class On : public State{
public:
    On(Context* context): State(context) {
    }

    virtual void on();
    virtual void off();
    virtual void destroy();
    virtual void status();

    ~On(){};
};
