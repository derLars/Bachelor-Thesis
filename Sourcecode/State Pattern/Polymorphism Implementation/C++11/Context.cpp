#include "Context.h"
#include "StateOn.h"

Context::Context() {
	numOfChanges = 0;
}

void Context::initialize(weak_ptr<Context> context) {
	state = make_unique<On>(context);

	functionMap.emplace(make_pair(ON, std::bind(&Context::on, this)));
	functionMap.emplace(make_pair(OFF, std::bind(&Context::off, this)));
	functionMap.emplace(make_pair(DESTROY, std::bind(&Context::destroy, this)));
}

void Context::input(int signal) {
	auto found = functionMap.find(signal);
	if (found != functionMap.end()) {
		(found->second)();
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
