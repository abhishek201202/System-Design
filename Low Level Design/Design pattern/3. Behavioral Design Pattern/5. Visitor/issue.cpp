#include<bits/stdc++.h>
using namespace std;

class Shape {
public:
    virtual int caculateArea();
    virtual void print();
};

class Square: public Shape {
private: 
    int x;
public:
    int caculateArea() const override {
        return x * x;
    }
    void print() {

    }
};

class Circle: public Shape {
private:
    int r;
public:
    int caculateArea() const override {
        return 3.14 * r * r;
    }
    void print() {

    }
}

// if i have to add new functions in circle it will voilate the open / closed principle
