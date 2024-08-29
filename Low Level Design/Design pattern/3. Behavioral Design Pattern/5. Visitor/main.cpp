#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Forward declarations
class Circle;
class Rectangle;
class Triangle;

// Visitor Interface
class ShapeVisitor {
public:
    virtual ~ShapeVisitor() = default;
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Rectangle& rectangle) = 0;
    virtual void visit(Triangle& triangle) = 0;
};

// Element Interface
class Shape {
public:
    virtual ~Shape() = default;
    virtual void accept(ShapeVisitor& visitor) = 0;
};

// Concrete Elements
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double radius) : radius(radius) {}
    double getRadius() const { return radius; }
    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this);
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double width, double height) : width(width), height(height) {}
    double getWidth() const { return width; }
    double getHeight() const { return height; }

    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this);
    }
};

// Concrete Visitors
class AreaCalculator : public ShapeVisitor {
public:
    void visit(Circle& circle) override {
        double area = M_PI * std::pow(circle.getRadius(), 2);
        std::cout << "Circle area: " << area << "\n";
    }

    void visit(Rectangle& rectangle) override {
        double area = rectangle.getWidth() * rectangle.getHeight();
        std::cout << "Rectangle area: " << area << "\n";
    }
};

class ShapePrinter : public ShapeVisitor {
public:
    void visit(Circle& circle) override {
        std::cout << "Circle with radius: " << circle.getRadius() << "\n";
    }

    void visit(Rectangle& rectangle) override {
        std::cout << "Rectangle with width: " << rectangle.getWidth() << " and height: " << rectangle.getHeight() << "\n";
    }
};

// Usage
int main() {
    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::make_shared<Circle>(5.0));
    shapes.push_back(std::make_shared<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_shared<Triangle>(3.0, 7.0));

    AreaCalculator areaCalculator;
    ShapePrinter shapePrinter;

    for (auto& shape : shapes) {
        shape->accept(areaCalculator);  // Calculate area of each shape
    }

    std::cout << "\n";

    for (auto& shape : shapes) {
        shape->accept(shapePrinter);  // Print details of each shape
    }

    return 0;
}
