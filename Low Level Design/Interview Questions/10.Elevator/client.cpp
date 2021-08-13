#include<iostream>
using namespace std;

/*============================================
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




Actor:
1) Passenger
2) Elevator cars
3) Floors
4) Doors
5) Button Panels
6) Dispatcher => Responsible for selecting the elevator car, when person press any key
7) Elevator System
8) Monitoring System



Use Cases:
1) Calling the elevator
2) Move / Stop the elevator
3) open / Close doors
4) Direction
5) Floor
6) Emergency Calls



Algorithm:
1) FCFS (first come first serve) (queue)
2) SSTF (Shortest Seek Time First) (minheap)
3) SCAN/Elevator Algorithm (array)
4) LOOK (BST)
5) Destination Dispatch Algorithm (KNN to find the best elevator)


============================================*/

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