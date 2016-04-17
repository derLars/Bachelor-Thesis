#include "StateOn.h"
#include "StateOff.h"
#include "StateDestroyed.h"

#include "Context.h"

void On::on() {
}

void On::off() {	
    if(auto tmp = context.lock()) {
        tmp->state = make_unique<Off>(context);
        tmp->numOfChanges++;
    }
}

void On::destroy() {	
    if(auto tmp = context.lock()) {
        tmp->state = make_unique<Destroyed>(context);
        tmp->numOfChanges++;
    }
}

void On::status() {
    cout << "light is on" << endl;
}
