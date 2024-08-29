/*
1. user can search vehicle on the app
2. user can rent vehicle
3. pay after the rent
4. user return vehicle
5. system can add / remove vehicle
6. multiple stores from where user can rent the vehicle.
7. Each store has its own inventory of vehicles
    - Single inventory for all the stores (this requirement could also be possible)
*/

#include<bits/stdc++.h>
using namespace std;

enum VehicalType {
    CAR, BIKE
};

// not following open / closed principle
class CarRentalSystem {
    vector<Store*> stores;
    CarRentalSystem();

    void addStore();
    void removeStore();

    void addVehicle(Store* store, Vehicle* vehicle);
    void removeVehicle(Store* store, Vehicle* vehicle);
};

// not following open / closed principle
class Store {
    string id;
    vector<Vehical*> vehicals;
    unordered_map<Vehical*, User*> vehToUserMp;
    unordered_map<User*, Vehical*> userToVehMp;

    Store() {}
    vector<Vehical*> searchVehical(VehicalType type);
    void rentVehicle(string vechicalId);
    void returnVehicle(Vehical* vehical);
}

class Vehical {
    string id;
    VehicalType type;
};

class Car: public Vehical {

}

class Bike: public Vehical {

}


class User {

}
