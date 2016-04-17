#include "Factory.h"
#include "Shape.h"

int main(int argc, char** argv) {
	enum OBJECT{C=0, T=1, R=2};

	Factory<Shape> factory;

	factory.add<C,Circle>();
	factory.add<T,Triangle>();
	factory.add<R,Rectangle>();

	auto instance = factory.getInstance(T);
	instance->foo();

	return 1;
}
