#include<bits/stdc++.h>
using namespace std;

class Car {
public:
    int getTopSpeed();
};
class EconomicCar1: public Car {
public:
    int getTopSpeed() {
        return 250;
    }
};
class EconomicCar2: public Car {
public:
    int getTopSpeed() {
        return 200;
    }
};
class LuxuryCar1: public Car {
public:
    int getTopSpeed() {
        return 150;
    }
};
class LuxuryCar2: public Car {
public:
    int getTopSpeed() {
        return 150;
    }
};

// Abstract factory
class AbstractFactory {
public:
    Car* getInstance(int price);
};
class EconomicCarFactory: public AbstractFactory {
public:
    Car* getInstance(int price) {
        if(price <= 30000) {
            return new EconomicCar1();
        }else if(price > 30000) {
            return new EconomicCar2();
        }
        return nullptr;
    }
};
class LuxuryCarFactory: public AbstractFactory {
public:
    Car* getInstance(int price) {
        if(price <= 30000) {
            return new LuxuryCar1();
        }else if(price > 30000) {
            return new LuxuryCar2();
        }
        return nullptr;
    }
};
class AbstractFactoryProducer {
public:
    static AbstractFactory* getFactoryInstance(string value) {
        if(value == "Economic") {
            return new EconomicCarFactory();
        }else if(value == "Luxury") {
            return new LuxuryCarFactory();
        }
        return nullptr;
    }
};
int main() {
    Car* car = AbstractFactoryProducer::getFactoryInstance("Economic")->getInstance(10000);
}