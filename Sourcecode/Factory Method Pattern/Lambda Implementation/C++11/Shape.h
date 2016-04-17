#ifndef SRC_SHAPE_H_
#define SRC_SHAPE_H_

#include <iostream>

using namespace std;

class Shape {
public:

  virtual ~Shape() {
  }

  void virtual foo(void) = 0;

  void virtual doOtherStuff(void) {
    cout << "everyone inherits this" << endl;
  }
};

class Rectangle: public Shape {
public:
  Rectangle() {
  }
  ~Rectangle() {
    //cout << "Rectangle destroyed" << endl;
  }

  void foo(void) {
    cout << "Rectangle is doing stuff" << endl;
  }
};

class Square : public Shape {//: public Rectangle {
public:
  Square() {
  }
  ~Square() {
    //cout << "Square destroyed" << endl;
  }

  void foo(void) {
    cout << "Square is doing stuff" << endl;
  }
};

class Circle: public Shape {
public:
  Circle() {
  }
  ~Circle() {
    //cout << "Circle destroyed" << endl;
  }

  void foo(void) {
    cout << "Circle is doing stuff" << endl;
  }
};

class Triangle: public Shape {
public:
  Triangle() {

  }
  ~Triangle() {
    //cout << "Triangle destroyed" << endl;
  }

  void foo(void) {
    cout << "Triangle is doing stuff" << endl;
  }
};

#endif /* SRC_SHAPE_H_ */
//###############################################################################
