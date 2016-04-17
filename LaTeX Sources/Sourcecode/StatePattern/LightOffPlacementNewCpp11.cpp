#include "LightOff.h"
#include "LightOn.h"
#include "Destroyed.h"
#include "Context.h"

void LightOff::on() {
    cout << "turn on!" << endl;
    if(auto tmp = context.lock()) {
        new(this) On(context);
        tmp->numOfChanges++;
    }
}

void LightOff::off() {
    cout << "already off!" << endl;
}

void LightOff::destroy() {
    cout << "Destroy!" << endl;
    if(auto tmp = context.lock()) {
        new(this) Destroyed(context);
        tmp->numOfChanges++;
    }
}

void LightOff::status() {
    if(auto tmp = context.lock()) {
        cout << "current state is: OFF!" << endl;
    }
}