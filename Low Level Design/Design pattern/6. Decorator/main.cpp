#include<bits/stdc++.h>
using namespace std;

// component Interface
class Coffee {
public:
    virtual string description() const = 0;
    virtual double cost() const = 0;
    virtual ~Coffee() {}
};
// concrete component
class SimpleCoffee : public Coffee {
public:
    string description() const override {
        return "Simple Coffee";
    }
    double cost() const override {
        return 2.0;
    }
};
// decorator
class CoffeeDecorator : public Coffee {
protected:
    Coffee* decoratedCoffee;
public:
    CoffeeDecorator(Coffee* coffee) : decoratedCoffee(coffee) {}
    string description() const override {
        return decoratedCoffee->description();
    }
    double cost() const override {
        return decoratedCoffee->cost();
    }
    virtual ~CoffeeDecorator() {
        delete decoratedCoffee;
    }
};
// concrete decorators
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}
    string description() const override {
        return decoratedCoffee->description() + ", Milk";
    }
    double cost() const override {
        return decoratedCoffee->cost() + 0.5;
    }
};
class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}
    string description() const override {
        return decoratedCoffee->description() + ", Sugar";
    }
    double cost() const override {
        return decoratedCoffee->cost() + 0.2;
    }
};
// client
int main() {
    Coffee* myCoffee = new SimpleCoffee();
    cout << myCoffee->description() << " $" << myCoffee->cost() << endl; // 2
    // Add milk to the coffee
    myCoffee = new MilkDecorator(myCoffee);
    cout << myCoffee->description() << " $" << myCoffee->cost() << endl; // 2.5
    // Add sugar to the coffee
    myCoffee = new SugarDecorator(myCoffee);
    cout << myCoffee->description() << " $" << myCoffee->cost() << endl; // 2.2
    delete myCoffee;  // Important to delete to avoid memory leaks
    return 0;
}




