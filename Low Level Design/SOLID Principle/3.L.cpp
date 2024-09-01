/*
* if class B is subtype of class A, then we should be able to replace 
object A with B without breaking the behaviour of program
* Subclass should extend the capability of parent class not narrow it down.
*/
#include<bits/stdc++.h>
using namespace std;

class Bike {
public:   
    virtual void turnOnEngine();
    virtual void accelerate();
};

class MotorCycle: public Bike {
    bool isEngine = false;
    int speed = 0;
public:
    void turnOnEngine() {
        isEngine = true;
    }
    void accelerate() {
        speed += 10;
    }
};

class Bicycle: public Bike {
public:
    // this is voilating Liskov principle
    void turnOnEngine() {
        throw new exception("there is no enginer");
    }
    void accelerate() {
        // do something
    }
}
