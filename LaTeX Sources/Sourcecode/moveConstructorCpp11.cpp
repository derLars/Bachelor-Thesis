#include <iostream>
#include "Shape.h"

using namespace std;
class Circle: public Shape {
public:
    Circle() {
        dynInt = new int(42);
    }
    ~Circle() { //Destructor
        delete dynInt;
    }

    Circle(const Circle &obj) { //Copy constructor  	
    	//deep copy:
    	dynInt = new int(*obj.dynInt);
    	//shallow copy:
        //dynInt = obj.dynInt;
    }

    void foo(void) {
        cout << "Circle calls foo()" << endl;
    }
    int* dynInt;
private:
    // Move constructor
    Circle(Circle &&obj) = default;
    // Copy assignment operator
    Circle& operator=(const Circle&) & = default;
    // Move assignment operator
    Circle& operator=(Circle&&) & = default;
};