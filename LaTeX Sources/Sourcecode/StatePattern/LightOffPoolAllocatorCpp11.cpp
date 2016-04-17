#include "LightOff.h"
#include "LightOn.h"
#include "Destroyed.h"
#include "Context.h"

void LightOff::on() {
    if(auto tmp = context.lock()) {
        tmp->state = allocate_shared<On>(tmp->alloc,context);
        tmp->numOfChanges++;
    }
}

void LightOff::off() {
    cout << "already off!" << endl;
}

void LightOff::destroy() {
    if(auto tmp = context.lock()) {
        tmp->state = allocate_shared<Destroyed>(tmp->alloc,context);
        tmp->numOfChanges++;
    }
}

void LightOff::status() {
    if(auto tmp = context.lock()) {
        cout << "current state is: OFF!" << endl;
    }
}