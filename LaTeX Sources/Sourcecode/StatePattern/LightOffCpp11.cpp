#include "LightOff.h"
#include "LightOn.h"
#include "Destroyed.h"
#include "Context.h"

void LightOff::on() {
    if(auto tmp = context.lock()) {
        tmp->state = make_unique<On>(context);
        tmp->numOfChanges++;
    }
}

void LightOff::off() {
    cout << "already off!" << endl;
}

void LightOff::destroy() {    
    if(auto tmp = context.lock()) {
        tmp->state = make_unique<Destroyed>(context);
        tmp->numOfChanges++;
    }
}

void LightOff::status() {
    if(auto tmp = context.lock()) {
        cout << "current state is: OFF!" << endl;
    }
}