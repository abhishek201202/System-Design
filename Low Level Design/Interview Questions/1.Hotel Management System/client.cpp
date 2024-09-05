#include<bits/stdc++.h>
using namespace std;

class Hotel{
    string Name;
    int id;
    Location location;
    vector<Room> room;
};

class Location{
    int pin;
    string street, area, city, country;
};

enum AccountStatus{
    ACTIVE, CLOSED, BLOCKED
};

class Account{
    string username;
    string password;
    AccountStatus accountStatus;
};

class Date{
    int day, month, year;
};

// person base class
class Person{
    string name;
    Account accountDetails;
    string phone;
};

// house keeper
class HouseKeeper: public Person{
public:
    vector<Room> getRoomsServiced(Date date);
};


// guest
class Guest: public Person{
    Search searchObj;
    Booking bookingObj;
public:
    vector<RoomBooking> getAllRoomBookings();
};

// receptionist
class Receptionist: public Person{
    Search searchObj;
    Booking bookingObj;
public:
    void checkInGuest(Guest guest, RoomBooking bookingInfo);
    void checkOutGuest(Guest guest, RoomBooking bookingInfo);
};


// admin
class admin: public Person{
public:
    void addRoom(Room roomDeatil);
    Room deleteRoom(string roomId);
    void editRoom(Room roomDetail);
};


enum RoomStyle{
    STANDARD, DELUX, FAMILY_SUIT
};

enum RoomStatus{
    AVAILABLE, RESERVED, NOT_AVAILABLE, OCCUPIED, SERVICE_IN_PROGRESS
};

class Room{
    string roomNumber;
    RoomStyle roomStyle;
    RoomStatus roomStatus;
    double bookingPrice;
    vector<class RoomKey> roomKeys;
    vector<class HouseKeepingLog> houseKeepingLogs;
};


class RoomKey{
    string keyId;
    string barCode;
    Date issuedAt;
    bool isActive;
    bool isMaster;
public:
    void assignRoom(Room room);
};


class HouseKeepingLog{
    string description;
    Date startDate;
    int duration;
    HouseKeeper housekeeper;
public:
    void addRoom(Room room);
};


class Search {
public:
    vector<Room> searchRoom(RoomStyle roomStyle, Date startDate, int duration);
};

/**
 * Decorator pattern is used to decorate the prices here.
 **/
class BaseRoomCharge{
    virtual double getCost();
};

class RoomCharge: public BaseRoomCharge{
    double cost;
    double getCost(){
        return cost;
    }
    void setCost(double cost){
        this -> cost = cost;
    }
};


class RoomServiceCharge: public BaseRoomCharge{
    double cost;
    BaseRoomCharge baseRoomCharge;
    double cost(){
        baseRoomCharge.setCost(baseRoomCharge.getCost() + cost);
        return baseRoomCharge.getCost();
    }
};

class RoomBooking {
    string bookingId;
    Date startDate;
    int durationInDays;
    BookingStatus bookingStatus;
    vector<Guest> guestList;
    vector<Room> roomInfo;
    BaseRoomChange totalRoomCharges;
};


class Booking {
public:
    RoomBooking createBooking(Guest guestInfo);
    RoomBooking createBooking(int bookingId);
};

int main(){

}

