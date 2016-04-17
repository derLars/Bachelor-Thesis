#include "StateOff.h"
#include "StateOn.h"
#include "StateDestroyed.h"

#include "Context.h"

void Off::on() {
    if(auto tmp = context.lock()) {
        tmp->state = allocate_shared<On>(tmp->alloc,context);
        tmp->numOfChanges++;
    }
}

void Off::off() {	    
}

void Off::destroy() {	
    if(auto tmp = context.lock()) {
        tmp->state = allocate_shared<Destroyed>(tmp->alloc, context);
        tmp->numOfChanges++;
    }
}

void Off::status() {
    cout << "light is off" << endl;
}
