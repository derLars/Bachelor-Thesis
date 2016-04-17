#include "Context.h"

int main(int argc, char** argv){
    Context* light = new Context();
    light->call(externalSignal);
   
    light->status();
    
    delete light;
    return 1;
}