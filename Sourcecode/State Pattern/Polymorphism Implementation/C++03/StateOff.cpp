#include "StateOff.h"
#include "StateOn.h"
#include "StateDestroyed.h"

#include "Context.h"

void Off::on() {
    delete context->state;
    context->state = new On(context);

    context->numOfChanges++;
}

void Off::off() {	    
}

void Off::destroy() {	
    delete context->state;
    context->state = new Destroyed(context);

    context->numOfChanges++;
}

void Off::status() {
    cout << "light is off" << endl;
}
