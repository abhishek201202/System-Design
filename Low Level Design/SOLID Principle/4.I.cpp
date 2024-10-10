/*
I: Interface Segmented Principle
Interfaces should be such that clients should not implement unnecessary functions they do not need.
*/
#include<bits/stdc++.h>
using namespace std;

// Not following Interface Segmented Principle
class RestaurantEmployee {
    public:
    virtual void washDishes();
    virtual void serveCustomers();
    virtual void cookFood();
};

class Waiter: public RestaurantEmployee {
public:
    void washDishes() {
        // not my job
    }
    void serveCustomers() {
        // do something
    }
    void cookFood() {
        // not my job
    }
};


// Following Interface Segmented Principle
class WaiterInterface {
public:
    virtual void serveCustomers();
    virtual void takeOrders();
};

class ChefInterface {
public:
    virtual void cookFood();
    virtual void decideMenu();
};

class Waiter: public WaiterInterface {
public:
    void serveCustomers() {
        // do something
    }
};
