#include<iostream>
#include<vector>
#include<string>
#include "Date.h"
#include "Room.h"
#include "Account.h"
using namespace std;



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










