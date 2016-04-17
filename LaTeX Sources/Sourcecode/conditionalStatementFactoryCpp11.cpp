#include "Shape.h"
#include <memory>

using namespace std;

class Factory {
public:
    Factory() {}
    ~Factory() {}

    unique_ptr<Shape> getInstance(int idx) {
        switch (idx) {
            case 0: return make_unique<Circle>();
            case 1: return make_unique<Triangle>();
            case 2: return make_unique<Rectangle>();
            default: return 0;
        }
    }
};