#include "Context.h"
#include "StateOn.h"

Context::Context() {
	numOfChanges = 0;
	state = new On(this);


	functionMap[ON]        	= &Context::on;
	functionMap[OFF] 		= &Context::off;
	functionMap[DESTROY]	= &Context::destroy;
}

Context::~Context() {
	delete state;
}

void Context::input(int signal) {
	if(functionMap.find(signal) != functionMap.end()) {
		(this->*functionMap[signal])();
	}
}

void Context::on() {
	state->on();
}

void Context::off() {
	state->off();
}

void Context::destroy() {
	state->destroy();
}

void Context::status() {
	state->status();
}
