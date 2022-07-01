//: C16:Shape.h
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>

class Shape {
public:
  Shape(void) {std::cout << "Shape::Shape   ";}
  virtual ~Shape() {std::cout << "Shape::~Shape\n";}
  virtual void draw() = 0;
  virtual void erase() = 0;
};

void Shape::draw (void) { std::cout << "just Shape\n"; }

class Circle : public Shape {
public:
  Circle() { std::cout << "Circle::Circle\n"; }
  ~Circle() { std::cout << "Circle::~Circle "; }
  void draw() { std::cout << "Circle::draw\n";}
  void erase() { std::cout << "Circle::erase\n";}
  void lol (void ) { Shape::draw() ;}
};

class Square : public Shape {
public:
  Square() {std::cout << "Square::Square\n";}
  ~Square() { std::cout << "Square::~Square "; }
  void draw() { std::cout << "Square::draw\n";}
  void erase() { std::cout << "Square::erase\n";}
};

class Line : public Shape {
public:
  Line() {  std::cout << "Line::Line\n";}
  ~Line() { std::cout << "Line::~Line "; }
  void draw() { std::cout << "Line::draw\n";}
  void erase() { std::cout << "Line::erase\n";}
};

#endif // SHAPE_H ///:~
