/*
This pattern helps us to decouple an abstraction from its implementation, so that two can vary independently.
*/

#include <iostream>
#include <memory>

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
        std::cout << "Red color applied.\n";
    }
};

class Blue : public Color {
public:
    void applyColor() const override {
        std::cout << "Blue color applied.\n";
    }
};

// Abstraction: Defines the abstraction's interface and 
// maintains a reference to the implementor
class Shape {
protected:
    std::shared_ptr<Color> color;

public:
    Shape(std::shared_ptr<Color> c) : color(c) {}
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

// Refined Abstractions: Extend the abstraction's interface
class Circle : public Shape {
public:
    Circle(std::shared_ptr<Color> c) : Shape(c) {}
    void draw() const override {
        std::cout << "Drawing a Circle. ";
        color->applyColor();
    }
};

class Square : public Shape {
public:
    Square(std::shared_ptr<Color> c) : Shape(c) {}
    void draw() const override {
        std::cout << "Drawing a Square. ";
        color->applyColor();
    }
};

// Usage
int main() {
    std::shared_ptr<Color> red = std::make_shared<Red>();
    std::shared_ptr<Color> blue = std::make_shared<Blue>();

    std::shared_ptr<Shape> redCircle = std::make_shared<Circle>(red);
    std::shared_ptr<Shape> blueSquare = std::make_shared<Square>(blue);

    redCircle->draw();  // Output: Drawing a Circle. Red color applied.
    blueSquare->draw(); // Output: Drawing a Square. Blue color applied.

    return 0;
}
