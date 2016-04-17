#include "LightOff.h"
#include "LightOn.h"
#include "Destroyed.h"
#include "Context.h"

void LightOff::on() {
    delete context->state;
    context->state = new LightOn(context);
    context->numOfChanges++;
}

void LightOff::off() {}

void LightOff::destroy() {	
	delete context->state;
	context->state = new Destroyed(context);
	context->numOfChanges++;
}

void LightOff::status() {
	cout << "current state is: OFF!"<< endl;
}