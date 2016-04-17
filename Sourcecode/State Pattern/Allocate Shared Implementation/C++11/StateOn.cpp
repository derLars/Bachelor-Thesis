#include "StateOn.h"
#include "StateOff.h"
#include "StateDestroyed.h"

#include "Context.h"

void On::on() {
}

void On::off() {	
    if(auto tmp = context.lock()) {
        tmp->state = allocate_shared<Off>(tmp->alloc, context);
        tmp->numOfChanges++;
    }
}

void On::destroy() {	
    if(auto tmp = context.lock()) {
        tmp->state = allocate_shared<Destroyed>(tmp->alloc, context);
        tmp->numOfChanges++;
    }
}

void On::status() {
    cout << "light is on" << endl;
}
