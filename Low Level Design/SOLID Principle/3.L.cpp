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
    void turnOnEnginer() {
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
