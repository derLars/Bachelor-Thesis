#include "Context.h"

int main(int argc, char** argv){
    Context light;

    light.input(Context::ON);
    light.status();

    light.input(Context::OFF);
    light.status();

    light.input(Context::DESTROY);
    light.status();
    
    return 1;
}
