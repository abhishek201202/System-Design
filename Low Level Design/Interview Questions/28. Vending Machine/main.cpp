#include<bits/stdc++.h>
using namespace std;

// state interface 
class VendingMachineState {
public:
    virtual void insertCoin() = 0;
    virtual void ejectCoin() = 0;
    virtual void pressButton() = 0;
    virtual void dispense() = 0;
    virtual ~VendingMachineState() {}
};

// concrete states

class VendingMachine;

class NoCoinState : public VendingMachineState {
private:
    VendingMachine* context;
public:
    NoCoinState(VendingMachine* ctx) : context(ctx) {}
    void insertCoin() override;
    void ejectCoin() override {
        cout << "You haven't inserted a coin.\n";
    }
    void pressButton() override {
        cout << "You need to insert a coin first.\n";
    }
    void dispense() override {
        cout << "Insert a coin first.\n";
    }
};

class HasCoinState : public VendingMachineState {
private:
    VendingMachine* context;
public:
    HasCoinState(VendingMachine* ctx) : context(ctx) {}
    void insertCoin() override {
        cout << "You already inserted a coin.\n";
    }
    void ejectCoin() override {
        cout << "Coin returned.\n";
        context->setState(new NoCoinState(context));
    }
    void pressButton() override {
        cout << "Button pressed.\n";
        context->setState(new SoldOutState(context));
    }
    void dispense() override {
        cout << "No item dispensed.\n";
    }
};

class SoldOutState : public VendingMachineState {
private:
    VendingMachine* context;
public:
    SoldOutState(VendingMachine* ctx) : context(ctx) {}
    void insertCoin() override {
        cout << "Sorry, the machine is sold out.\n";
    }
    void ejectCoin() override {
        cout << "No coin to return.\n";
    }
    void pressButton() override {
        cout << "No item dispensed.\n";
    }
    void dispense() override {
        cout << "No item dispensed.\n";
    }
};


// context
class VendingMachine {
private:
    VendingMachineState* currentState;
public:
    VendingMachine() {
        currentState = new NoCoinState(this);
    }
    void setState(VendingMachineState* state) {
        delete currentState;
        currentState = state;
    }
    void insertCoin() {
        currentState->insertCoin();
    }
    void ejectCoin() {
        currentState->ejectCoin();
    }
    void pressButton() {
        currentState->pressButton();
        currentState->dispense();
    }
    ~VendingMachine() {
        delete currentState;
    }
};


// client
int main() {
    VendingMachine machine;
    machine.insertCoin();
    machine.pressButton();
    machine.ejectCoin();
    // Change the state to simulate sold-out condition
    machine.setState(new SoldOutState(&machine));
    machine.insertCoin();
    machine.pressButton();
    return 0;
}
