/*
This pattern helps us to decouple an abstraction from its implementation, so that two can vary independently.
*/

#include<bits/stdc++.h>
using namespace std;

// Implementor: The base interface for the implementation hierarchy
class Color {
public:
    virtual ~Color() = default;
    virtual void applyColor() const = 0;
};

// Concrete Implementors: Implement the base interface
class Red : public Color {
public:
    void applyColor() const override {
        cout << "Red color applied.\n";
    }
};

class Blue : public Color {
public:
    void applyColor() const override {
        cout << "Blue color applied.\n";
    }
};

// Abstraction: Defines the abstraction's interface and 
// maintains a reference to the implementor
class Shape {
protected:
    shared_ptr<Color> color;
public:
    Shape(shared_ptr<Color> c) : color(c) {}
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

// Refined Abstractions: Extend the abstraction's interface
class Circle : public Shape {
public:
    Circle(shared_ptr<Color> c) : Shape(c) {}
    void draw() const override {
        cout << "Drawing a Circle. ";
        color->applyColor();
    }
};

class Square : public Shape {
public:
    Square(shared_ptr<Color> c) : Shape(c) {}
    void draw() const override {
        cout << "Drawing a Square. ";
        color->applyColor();
    }
};

// Usage
int main() {
    shared_ptr<Color> red = make_shared<Red>();
    shared_ptr<Color> blue = make_shared<Blue>();

    shared_ptr<Shape> redCircle = make_shared<Circle>(red);
    shared_ptr<Shape> blueSquare = make_shared<Square>(blue);

    redCircle->draw();  // Output: Drawing a Circle. Red color applied.
    blueSquare->draw(); // Output: Drawing a Square. Blue color applied.

    return 0;
}
