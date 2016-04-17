#include "StateOn.h"
#include "StateOff.h"
#include "StateDestroyed.h"

#include "Context.h"

void On::on() {
}

void On::off() {	
    new(this) Off(context);
}

void On::destroy() {	
    new(this) Destroyed(context);
}

void On::status() {
    cout << "light is on" << endl;
}
