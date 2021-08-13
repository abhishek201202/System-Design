#include<iostream>
#include<vector>
using namespace std;

/* =========================================
=> inherit rider and driver from the person class 
=> to show the use case of inheritance 

Rider => to extend in the interview make 2 type of customer 
      => company employes and normal user
=> rider_id
=> x_coordinate
=> y_coordinate
=> void registerForRide()
=> void unRegisterForRide()

Cab
=> cab_id
=> rider_id
=> driver_id
=> x_coordinate
=> y_coordinate
=> void startRide()
=> void endRide()
=> void calCost()

Driver
=> driver_id
=> cab_id
=> isDriving
=> void changeMode()
==========================================*/



class Location{
private:
    int x, y;
public:
    int distance(Location another);
};


class Cab{
private:
    int cab_id;
    int rider_id;
    int driver_id;
    Location currentLocation;
    Location destinationLocation;

public:
    void startRide();
    void endRide();
    int calCost();
};



class Rider{
private:
    int rider_id;
    int x_coordinate;
    int y_coordinate;
public:
    void RegisterForRide(Location source, Location destination);
    void UnRegisterForRide();
};



class Driver{
private:
    int driver_id;
    int cab_id;
    bool isDriving;
public:
    void changeMode();
};


class Uber{
private:
    vector<Cab> cabs;
    vector<Driver> drivers;
public:
    int assignCab(); // return nearest available cab id
};



int32_t main(){

}