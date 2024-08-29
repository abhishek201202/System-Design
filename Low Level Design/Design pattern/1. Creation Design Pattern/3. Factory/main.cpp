/*
It is used when all the object creation and business logic we need to keep at one place.
*/
#include<bits/stdc++.h>
using namespace std;

class Shape {
public:
    void computeArea();
};

class Square: public Shape {
public:
    void computeArea() {
        // do something
    }
};

class Circle: public Shape {
public:
    void computeArea() {
        // do something
    } 
};

class ShapeInstaceFactory {
public:
    static Shape* getShapeInstace(string value) {
        if(value == "Circle") {
            return new Circle();
        }else if(value == "Square") {
            return new Square();
        }else{
            return nullptr;
        }
    }
};
