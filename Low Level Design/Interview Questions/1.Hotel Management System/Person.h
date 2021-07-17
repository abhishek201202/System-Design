#include<iostream>
#include<vector>
#include<string>
#include "Date.h"
#include "Room.h"
#include "Account.h"
#include "services.h"
using namespace std;

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




