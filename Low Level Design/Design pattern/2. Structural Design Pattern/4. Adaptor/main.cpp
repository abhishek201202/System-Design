/*
This pattern acts as a bridge or intermediate between 2 incompatible interfaces.
*/
#include<bits/stdc++.h>
using namespace std;

// target interface
class Target {
public:
    virtual void request() const {
        std::cout << "Target: The default target's behavior.\n";
    }
    virtual ~Target() = default;
};
// adaptee class
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Adaptee: The specific request.\n";
    }
};
// adapter class
class Adapter : public Target {
private:
    Adaptee* adaptee;
public:
    Adapter(Adaptee* a) : adaptee(a) {}
    void request() const override {
        std::cout << "Adapter: Translating request to specific request.\n";
        adaptee->specificRequest();
    }
    ~Adapter() {
        delete adaptee;
    }
};
// client
int main() {
    Adaptee* adaptee = new Adaptee();
    Target* target = new Adapter(adaptee);
    target->request();  // The client calls the method defined in the Target interface
    delete target;
    return 0;
}

