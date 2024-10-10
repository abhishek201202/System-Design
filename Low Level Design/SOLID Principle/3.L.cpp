/*
L: Liskov Substitution
* if class B is subtype of class A, then we should be able to replace 
object A with B without breaking the behaviour of program
* Subclass should extend the capability of parent class not narrow it down.
*/
#include<bits/stdc++.h>
using namespace std;

// Violating Liskov substitution principle
class Rectangle {
public:
    virtual void setWidth(double w) { width = w; }
    virtual void setHeight(double h) { height = h; }
    double getArea() const { return width * height; }

protected:
    double width = 0, height = 0;
};

class Square : public Rectangle {
public:
    void setWidth(double w) override {
        width = w;
        height = w; // Violation: Square is not substitutable for Rectangle
    }
    
    void setHeight(double h) override {
        width = h;
        height = h; // Violation: Square is not substitutable for Rectangle
    }
};

// Following Liskov substitution principle
class Shape {
public:
    virtual double getArea() const = 0; // pure virtual function
    virtual ~Shape() = default; // virtual destructor for polymorphism
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    void setWidth(double w) { width = w; }
    void setHeight(double h) { height = h; }

    double getArea() const override {
        return width * height;
    }

protected:
    double width, height;
};

class Square : public Shape {
public:
    Square(double side) : sideLength(side) {}

    void setSideLength(double side) { sideLength = side; }

    double getArea() const override {
        return sideLength * sideLength;
    }

private:
    double sideLength;
};
