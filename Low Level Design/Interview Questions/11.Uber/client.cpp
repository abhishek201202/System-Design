/*
Functional Requirements - 
1. Register a rider.
2. Register a driver/cab
3. Update a cab's location
4. A driver can switch on/off his availability
5. A rider can book a cab
6. Fetch history of all rides taken by a rider.
7. End the Trip


Non Functional Requirements - 
1. A cab has only 1 driver.
2. Sharing of cab is not allowed between riders
3. There is a single type of cab

Design Patterns - 
1. Singleton pattern for centralized system
2. Observer Pattern for real time updates.
3. Strategy pattern for pricing algorithm
4. Factory pattern for vehicle creation
5. Builder pattern for ride booking
6. Decorator pattern for enhacing features (e.g premium seating)
7. Facade pattern for Ride Management

*/


#include<bits/stdc++.h>
using namespace std;

class User {
protected:
    int userID;
    string name;
    string phoneNumber;
public:
    User(int id, const string& name, const string& phone) : userID(id), name(name), phoneNumber(phone) {}
    virtual void displayInfo() const = 0; // Pure virtual function
};

class Passenger : public User {
public:
    Passenger(int id, const string& name, const string& phone) : User(id, name, phone) {}
    void displayInfo() const override {
        cout << "Passenger: " << name << ", Phone: " << phoneNumber << endl;
    }
};

class Driver : public User {
    Vehicle* vehicle;  // Composition: Driver has a Vehicle
public:
    Driver(int id, const string& name, const string& phone, Vehicle* vehicle) : User(id, name, phone), vehicle(vehicle) {}
    void displayInfo() const override {
        cout << "Driver: " << name << ", Vehicle: " << vehicle->getDetails() << endl;
    }
    Vehicle* getVehicle() const {
        return vehicle;
    }
};


class Vehicle {
    string licensePlate;
    string model;
public:
    Vehicle(const string& plate, const string& model) : licensePlate(plate), model(model) {}
    string getDetails() const {
        return model + " (" + licensePlate + ")";
    }
};


class Location {
    double latitude;
    double longitude;
public:
    Location(double lat, double lon) : latitude(lat), longitude(lon) {}

    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }

    double distanceTo(const Location& other) const {
        // Implement a method to calculate distance between two locations
        // For simplicity, you can use Euclidean distance or a more accurate Haversine formula
    }
};

enum class RideStatus { Requested, Accepted, InProgress, Completed, Canceled };

class Ride {
    int rideID;
    Passenger* passenger;
    Driver* driver;
    Location pickup;
    Location dropoff;
    RideStatus status;
    double fare;
public:
    Ride(int id, Passenger* psg, Driver* drv, const Location& pickup, const Location& dropoff) : rideID(id), passenger(psg), driver(drv), pickup(pickup), dropoff(dropoff), status(RideStatus::Requested), fare(0.0) {}

    void startRide() {
        status = RideStatus::InProgress;
        // Calculate fare based on distance
        fare = pickup.distanceTo(dropoff) * 10; // Example: $10 per km
    }
    void completeRide() {
        status = RideStatus::Completed;
        // Process payment
    }
    void cancelRide() {
        status = RideStatus::Canceled;
    }
    RideStatus getStatus() const {
        return status;
    }
};


class Payment {
public:
    void processPayment(Passenger* passenger, Driver* driver, double amount) {
        cout << "Processing payment of $" << amount << " from " << passenger->getName() to << driver->getName() << endl;
    }
};


class RideManager {
    vector<Ride*> activeRides;
public:
    Ride* requestRide(Passenger* passenger, Driver* driver, const Location& pickup, const Location& dropoff) {
        Ride* newRide = new Ride(activeRides.size() + 1, passenger, driver, pickup, dropoff);
        activeRides.push_back(newRide);
        return newRide;
    }
    void updateRideStatus(Ride* ride, RideStatus status) {
        // Update the status of the ride
        if (ride->getStatus() == RideStatus::InProgress && status == RideStatus::Completed) {
            ride->completeRide();
        } else if (status == RideStatus::Canceled) {
            ride->cancelRide();
        }
    }
};


int main() {
    // Create Users
    Passenger* passenger = new Passenger(1, "Alice", "1234567890");
    Vehicle* vehicle = new Vehicle("AB1234", "Toyota Prius");
    Driver* driver = new Driver(1, "Bob", "0987654321", vehicle);

    // Create Locations
    Location pickup(40.712776, -74.005974); // NYC coordinates
    Location dropoff(40.730610, -73.935242); // Somewhere else in NYC

    // Ride Manager
    RideManager rideManager;
}
