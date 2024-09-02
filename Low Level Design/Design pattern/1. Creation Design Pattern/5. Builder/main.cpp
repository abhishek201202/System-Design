/*
When you want to create object step by step
*/
#include<bits/stdc++.h>
using namespace std;

class House {
private:
    string walls;
    string doors;
public:
    void setWalls(const string& walls) { this->walls = walls; }
    void setDoors(const string& doors) { this->doors = doors; }
};

class HouseDirector {
private:
    HouseBuilder* builder;
public:
    void setBuilder(HouseBuilder* b) {
        builder = b;
    }
    House* constructHouse() {
        builder->buildWalls();
        builder->buildDoors();
        return builder->getHouse();
    }
};

class HouseBuilder {
public:
    virtual ~HouseBuilder() {}
    virtual void buildWalls() = 0;
    virtual void buildDoors() = 0;
    virtual House* getHouse() = 0;
};

class ConcreteHouseBuilder : public HouseBuilder {
private:
    House* house;
public:
    ConcreteHouseBuilder() { house = new House(); }
    ~ConcreteHouseBuilder() { delete house; }
    void buildWalls() override {
        house->setWalls("Concrete Walls");
    }
    void buildDoors() override {
        house->setDoors("Wooden Doors");
    }
    House* getHouse() override {
        return house;
    }
};

int main() {
    HouseDirector director;
    ConcreteHouseBuilder concreteBuilder;
    director.setBuilder(&concreteBuilder);
    House* house = director.constructHouse();
    house->showHouse();
}