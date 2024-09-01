#include<bits/stdc++.h>
using namespace std;

class VendingMachine; // Forward declaration

class State {
public:
    virtual ~State() = default;
    virtual void insertMoney(VendingMachine* machine) = 0;
    virtual void ejectMoney(VendingMachine* machine) = 0;
    virtual void selectItem(VendingMachine* machine) = 0;
    virtual void dispenseItem(VendingMachine* machine) = 0;
};


class IdleState : public State {
public:
    void insertMoney(VendingMachine* machine) override;
    void ejectMoney(VendingMachine* machine) override;
    void selectItem(VendingMachine* machine) override;
    void dispenseItem(VendingMachine* machine) override;
};

class HasMoneyState : public State {
public:
    void insertMoney(VendingMachine* machine) override;
    void ejectMoney(VendingMachine* machine) override;
    void selectItem(VendingMachine* machine) override;
    void dispenseItem(VendingMachine* machine) override;
};

class SelectionState : public State {
public:
    void insertMoney(VendingMachine* machine) override;
    void ejectMoney(VendingMachine* machine) override;
    void selectItem(VendingMachine* machine) override;
    void dispenseItem(VendingMachine* machine) override;
};

class DispenseState : public State {
public:
    void insertMoney(VendingMachine* machine) override;
    void ejectMoney(VendingMachine* machine) override;
    void selectItem(VendingMachine* machine) override;
    void dispenseItem(VendingMachine* machine) override;
};

class VendingMachine {
public:
    VendingMachine() : currentState(new IdleState()), itemCount(0) {}
    void setState(State* state) {
        currentState.reset(state);
    }
    void insertMoney() {
        currentState->insertMoney(this);
    }
    void ejectMoney() {
        currentState->ejectMoney(this);
    }
    void selectItem() {
        currentState->selectItem(this);
    }
    void dispenseItem() {
        currentState->dispenseItem(this);
    }
    void setItemCount(int count) {
        itemCount = count;
    }
    int getItemCount() const {
        return itemCount;
    }
private:
    unique_ptr<State> currentState;
    int itemCount;
};
