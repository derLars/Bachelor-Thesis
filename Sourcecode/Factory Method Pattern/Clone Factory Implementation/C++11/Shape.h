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

private:

};

class Rectangle: public Shape {
public:
  Rectangle() {
  }
  ~Rectangle() {
    //cout << "Rectangle destroyed" << endl;
  }

  Rectangle(const Rectangle &obj) { //Copy Constructor	  
  }

  void foo(void) {
    cout << "Rectangle calls foo()" << endl;
  }

private :
  Rectangle(Rectangle&&) = default;                    // Move constructor
  Rectangle& operator=(const Rectangle&) & = default;  // Copy assignment operator
  Rectangle& operator=(Rectangle&&) & = default;       // Move assignment operator
};

class Square : public Shape {//: public Rectangle {
public:
  Square() {
  }
  ~Square() {
    //cout << "Square destroyed" << endl;
  }

  Square(const Square &obj) {  	  //Copy Constructor	  
  }

  void foo(void) {
    cout << "Square calls foo()" << endl;
  }

private :
  Square(Square&&) = default;                    // Move constructor
  Square& operator=(const Square&) & = default;  // Copy assignment operator
  Square& operator=(Square&&) & = default;       // Move assignment operator
};

class Circle: public Shape {
public:
  Circle() {	 
  }
  ~Circle() {
    //cout << "Circle destroyed" << endl;
  }

  Circle(const Circle &obj) {   //Copy Constructor	  
  }

  void foo(void) {
    cout << "Circle calls foo()" << endl;
  }

private :
  Circle(Circle&&) = default;                    // Move constructor
  Circle& operator=(const Circle&) & = default;  // Copy assignment operator
  Circle& operator=(Circle&&) & = default;       // Move assignment operator
};

class Triangle: public Shape {
public:
  Triangle() {

  }
  ~Triangle() {
    //cout << "Triangle destroyed" << endl;
  }

  Triangle(const Triangle &obj) {   //Copy Constructor	  
  }

  void foo(void) {
    cout << "Triangle calls foo()" << endl;
  }

private :
  Triangle(Triangle&&) = default;                    // Move constructor
  Triangle& operator=(const Triangle&) & = default;  // Copy assignment operator
  Triangle& operator=(Triangle&&) & = default;       // Move assignment operator
};

#endif /* SRC_SHAPE_H_ */
