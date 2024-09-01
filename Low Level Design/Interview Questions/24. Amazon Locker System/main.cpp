/*
https://leetcode.com/discuss/interview-question/system-design/233869/Design-Amazon-Locker-system
Amazon locker - https://www.youtube.com/watch?v=GuE_P4IfPio
Amazon locker lld - https://www.youtube.com/watch?v=Ku6xVU2lM38 (starts at 28:40)

FR - 
1. Assign a closest locker to a person given current co-ordinates( where customer wants )
2. After order is delivered by courier service to customer specified amazon locker, a 6 digit code will be sent to customer .
3. Item will be placed in Amazon locker for 3 days
4. After 3 days, if Item is not picked up from the locker, refund process will be initiated
5. Amazon locker will be assigned to customer based on the size of the locker ( S,M,L,XL,XXL)
6. Only items that are eligible to be put in locker can be assigned to amazon locker .i.e Not all items can be placed inside locker (like furniture can't be put inside amazon locker)
7. Access to Amazon locker will depend on Store's opening and closing time.(Since Amazon locker are placed inside stores,malls etc)
8. Items can be returned to Amazon locker as well .
9. Items that are eligible Amazon locker item, can only be returned by customer
10. Once the Door is closed. User's code will be expired. (User will not be able to open the locker now)
*/

#include<bits/stdc++.h>
using namespace std;

// Package Class
class Package {
public:
    string packageID;
    string size;
    string customerID;
    Package(const string& id, const string& sz, const string& custID) : packageID(id), size(sz), customerID(custID) {}
};

// Customer Class
class Customer {
public:
    string customerID;
    string name;
    string phoneNumber;
    string email;
    Customer(const string& id, const string& nm, const string& phone, const string& mail) : customerID(id), name(nm), phoneNumber(phone), email(mail) {}

    void retrievePackage() {
        cout << "Package retrieved by " << name << endl;
    }
};

// Locker Class
class Locker {
public:
    string lockerID;
    string size;
    bool isAvailable;
    Package* currentPackage;

    Locker(const string& id, const string& sz) : lockerID(id), size(sz), isAvailable(true), currentPackage(nullptr) {}

    void assignPackage(Package* package) {
        currentPackage = package;
        isAvailable = false;
        cout << "Package " << package->packageID << " assigned to locker " << lockerID << endl;
    }

    void releasePackage() {
        cout << "Package " << currentPackage->packageID << " retrieved from locker " << lockerID << endl;
        currentPackage = nullptr;
        isAvailable = true;
    }
};

// LockerStation Class
class LockerStation {
public:
    string stationID;
    string location;
    vector<Locker> lockers;
    LockerStation(const string& id, const string& loc, const vector<Locker>& lckrs) : stationID(id), location(loc), lockers(lckrs) {}
    Locker* findAvailableLocker(const string& size) {
        for (auto& locker : lockers) {
            if (locker.isAvailable && locker.size == size) {
                return &locker;
            }
        }
        return nullptr;
    }
};

// DeliveryPersonnel Class
class DeliveryPersonnel {
public:
    string personnelID;
    string name;
    DeliveryPersonnel(const string& id, const string& nm): personnelID(id), name(nm) {}
    void depositPackage(LockerStation& station, Package* package) {
        Locker* locker = station.findAvailableLocker(package->size);
        if (locker) {
            locker->assignPackage(package);
        } else {
            cout << "No available locker for package " << package->packageID << endl;
        }
    }
};

// NotificationService Class
class NotificationService {
public:
    void sendNotification(const Customer& customer, const string& message) {
        cout << "Notification sent to " << customer.name << ": " << message << endl;
    }
};

// LockerSystem Class
class LockerSystem {
public:
    vector<LockerStation> stations;

    void registerLockerStation(const LockerStation& station) {
        stations.push_back(station);
    }

    void assignLockerToPackage(Package* package) {
        for (auto& station : stations) {
            Locker* locker = station.findAvailableLocker(package->size);
            if (locker) {
                locker->assignPackage(package);
                return;
            }
        }
        cout << "No available locker found for package " << package->packageID << endl;
    }

    void releaseLocker(LockerStation& station, int lockerID) {
        if (lockerID < station.lockers.size()) {
            station.lockers[lockerID].releasePackage();
        }
    }
};

// Main Function to simulate the system
int main() {
    // Create some lockers
    vector<Locker> lockers = { Locker("L1", "Small"), Locker("L2", "Medium"), Locker("L3", "Large") };
    
    // Create a locker station
    LockerStation station1("Station1", "Location1", lockers);
    
    // Register the station in the system
    LockerSystem system;
    system.registerLockerStation(station1);
    
    // Create a customer
    Customer customer("C1", "John Doe", "1234567890", "john@example.com");
    
    // Create a package
    Package package("P1", "Medium", customer.customerID);
    
    // Create a delivery person and deliver the package
    DeliveryPersonnel deliveryPerson("D1", "Jane Doe");
    deliveryPerson.depositPackage(station1, &package);
    
    // Notify customer
    NotificationService notificationService;
    notificationService.sendNotification(customer, "Your package is ready for pickup.");
    
    // Customer retrieves the package
    system.releaseLocker(station1, 1);
    customer.retrievePackage();

    return 0;
}
