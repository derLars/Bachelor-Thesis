#include "StateOff.h"
#include "StateOn.h"
#include "StateDestroyed.h"

#include "Context.h"

void Off::on() {
    new(this) On(context);
}

void Off::off() {	    
}

void Off::destroy() {	
    new(this) Destroyed(context);
}

void Off::status() {
    cout << "light is off" << endl;
}
