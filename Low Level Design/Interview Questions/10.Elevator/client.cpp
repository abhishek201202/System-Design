#include<iostream>
using namespace std;

/*
Fucntional Reqirements:
1) state of the elevator
    - up, down, idle
2) transfer passenger from one place to another 
3) open door when idle at a floor
4) 200 elevator floor + 50 elevator car
5) specs of elevator car:
    - No of passengers
    - maximum load
    - max speed
6) Minimize:
    - wait time of system
    - wait time of individual passenger

7) Throughput
8) Power usage / Cost


Non Functional Requirements:
1) Emergency breaks / Alarms
2) VIP or utility elevator cars
3) Monitoring system




Objects:
1. Building
2. Floors
3. Elevator cars
4. Floors
5. Doors
6. Button Panels (internal and external)
7. Display
8. Dispatcher => Responsible for selecting the elevator car, when person press any key
9. Elevator System
10. Monitoring System

Algorithm:
1) FCFS (first come first serve) (queue)
2) SSTF (Shortest Seek Time First) (minheap)
3) SCAN/Elevator Algorithm (array)
4) LOOK (BST)
5) Destination Dispatch Algorithm (KNN to find the best elevator)


Display
--------------------
int floor;
Direction direction;

ElevatorCar
--------------------
Display display;
Direction currDir;
Status status;
Button *internalButton;
move(int destinationFloor, Direction dir);


enum Direction {
    UP, DOWN
}

enum Status {
    IDLE, MOVING
}

Button
--------------------
pressButton(int button);


InternalButton
--------------------
Dispatcher* internalButtonDispatcher;
pressButton(int button);

ExternalButton
--------------------
Dispatcher* externalButtonDispatcher;
pressButton(int button); -> this will call the submitRequest of Dispatcher


ElevatorController
--------------------
ElevatorCar obj;
Algorithm schedulingAlgo;
acceptNewRequest(int floor, Direction dir);
controlCar();


Dispatcher
---------------------


InternalDispatcher
---------------------
vector<ElevatorController> controllers;
Algorithm dispatchingAlgo;
submitRequest();


ExternalDispatcher
---------------------
vector<ElevatorController> controllers;
submitRequest();

Floor
---------------
int id;
Button externalButton;

Building
---------------
vector<Floor> floors;



PressButton -> submitRequest (Dispatcher) -> accepthNewRequest (ElevatorController) -> controlCar(ElevatorController) -> move (ElevatorCar)


*/

enum State{
    UP, DOWN, IDLE
};

enum FloorNumber{
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10
};

class Elevator{
    vector<Button> buttons;
    vector<Button> ActiveButton;
    Door door;
    State currState;
    FloorNumber floorNumber; 
    int speed;
    int maxWeight;
    Transition transitTo;

public:
    void changeState();
    void findLoadedWeight();
};


class WeighingMachine{
public:
    int getTotalWeight();
};

class Transition{
    Floor lastFloor;
    Floor nextFloor;
    Floor currFloor;
};


class Floor{
    int floorNumber;
};


class Button{
    int FloorNumber;
public:
    void PressUp();
    void PressDown();
};

class ElevatorButton : public Button {
public:
    virtual void PressUp();
    virtual void PressDown();
};

class HallButton : public Button {
public:
    virtual void PressUp();
    virtual void PressDown();
};

class Door{
public:
    void open();
    void close();
    void isOpen();
};



int32_t main(){
    
}