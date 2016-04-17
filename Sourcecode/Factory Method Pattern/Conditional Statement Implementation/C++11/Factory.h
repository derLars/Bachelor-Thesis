#ifndef SRC_FACTORY_H_
#define SRC_FACTORY_H_

#include <iostream>

#include "Shape.h"
#include <memory>

using namespace std;

class Factory {
public:
    Factory() {}
    ~Factory() {}

    shared_ptr<Shape> getInstance(int idx) {
        switch (idx) {
            case 0: return make_shared<Circle>();
            case 1: return make_shared<Triangle>();
            case 2: return make_shared<Rectangle>();
            default: return 0;
        }
    }
};

#endif /* SRC_FACTORY_H_ */
