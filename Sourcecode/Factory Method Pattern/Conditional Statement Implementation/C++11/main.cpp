#include "Factory.h"

int main(int argc, char** argv) {
    enum OBJECT{C=0, T=1, R=2};

    Factory factory;

    auto instance = factory.getInstance(T);
    instance->foo();

    return 1;
}
