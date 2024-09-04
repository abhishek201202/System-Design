/*
1. user can search vehicle on the app
2. user can rent vehicle
3. pay after the rent
4. user return vehicle
5. system can add / remove vehicle
6. multiple stores from where user can rent the vehicle.
7. Each Store has its own inventory
*/

#include<bits/stdc++.h>
using namespace std;

enum VehicalType {
    CAR, BIKE
};

class CarRentalSystem {
    vector<Store*> stores;
    vector<User*> users;
    CarRentalSystemDao *storeDao, *userDao, *vehicleDao;
    CarRentalSystem() {
        storeDao = new StoreCarRentalSystemDao();
        userDao = new UserCarRentalSystemDao();
        vehicleDao = new VehicleCarRentalSystemDao();
    }
};

class CarRentalSystemDao {
};

class StoreCarRentalSystemDao: public CarRentalSystemDao {
    void addStore();
    void removeStore();
}
class UserCarRentalSystemDao: public CarRentalSystemDao {
    void addUser();
    void deleteUser();
}
class VehicleCarRentalSystemDao: public CarRentalSystemDao {
    void addVehicle(Store* store, Vehicle* vehicle);
    void removeVehicle(Store* store, Vehicle* vehicle);
}

class Store {
    string id;
    VehicleInventory *carInventoryObj, *bikeInventoryObj;
    Store() {
        carInventoryObj = new CarInventory();
        bikeInventoryObj = new BikeInventory();
    }
}

class VehicleInventory {
    vector<Vehical*> vehicals;
    unordered_map<Vehical*, User*> vehToUserMp;
    unordered_map<User*, Vehical*> userToVehMp;

    vector<Vehical*> searchVehical(VehicalType type);

    virtual void addVehical(Vehical* vehical);
    virtual void removeVehical(Vehical* vehical);

    virtual void rentVehicle(string vechicalId);
    virtual void returnVehicle(Vehical* vehical);
};

class CarInventory: public VehicleInventory {
    void addVehical(Vehical* vehical);
    void removeVehical(Vehical* vehical);
    void rentVehicle(string vechicalId);
    void returnVehicle(Vehical* vehical);
};

class BikeInventory: public VehicleInventory {
    void addVehical(Vehical* vehical);
    void removeVehical(Vehical* vehical);
    void rentVehicle(string vechicalId);
    void returnVehicle(Vehical* vehical);
};


class Vehical {
    string id;
    VehicalType type;
};

class Car: public Vehical {

};

class Bike: public Vehical {

};


class User {
    string name;
    string emailId;
    string phoneNumber;
};
