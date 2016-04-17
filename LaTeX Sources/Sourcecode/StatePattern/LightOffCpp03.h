#include "State.h"

class LightOff : public State{
public:
    LightOff(Context* context): State(context) {}

    virtual void on();
    virtual void off();
    virtual void destroy();
    virtual void status();

    ~LightOff(){};
};