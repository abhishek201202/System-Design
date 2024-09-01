/*
* if class B is subtype of class A, then we should be able to replace 
object A with B without breaking the behaviour of program
* Subclass should extend the capability of parent class not narrow it down.
*/
#include<bits/stdc++.h>
using namespace std;

class Bird {
public:
    virtual void fly() {
        std::cout << "Flying in the sky." << std::endl;
    }
};

class Penguin : public Bird {
public:
    void fly() override {
        throw std::logic_error("Penguins can't fly!");
    }
};

void makeBirdFly(Bird& bird) {
    bird.fly();
}

int main() {
    Bird sparrow;
    Penguin penguin;

    makeBirdFly(sparrow);  // Works fine
    makeBirdFly(penguin);  // Throws an error at runtime

    return 0;
}
