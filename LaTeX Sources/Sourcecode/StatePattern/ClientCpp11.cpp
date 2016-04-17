#include "Context.h"

int main(int argc, char** argv){
    auto light = make_shared<Context>();
    light->initialize(light);

    light->call(externalSignal);

    light->status();
    return 1;
}