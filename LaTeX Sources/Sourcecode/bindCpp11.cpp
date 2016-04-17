int add(int a, int b) {
    return a + b;
}

auto addOne = bind(&add, 1, placeholders::_1);
auto addTwo = bind(&add, 2, placeholders::_1);
cout << addOne(3) << ", " << addTwo(5) << endl;