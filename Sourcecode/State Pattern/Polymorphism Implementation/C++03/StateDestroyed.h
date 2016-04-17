#include "State.h"

class Destroyed : public State{
public:
    Destroyed(Context* context): State(context) {
    }

    virtual void on();
    virtual void off();
    virtual void destroy();
    virtual void status();

    ~Destroyed(){};
};
