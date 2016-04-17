#include "StateOn.h"
#include "StateOff.h"
#include "StateDestroyed.h"

#include "Context.h"

void On::on() {
}

void On::off() {	
    delete context->state;
    context->state = new Off(context);

    context->numOfChanges++;
}

void On::destroy() {	
    delete context->state;
    context->state = new Destroyed(context);

    context->numOfChanges++;
}

void On::status() {
    cout << "light is on" << endl;
}
