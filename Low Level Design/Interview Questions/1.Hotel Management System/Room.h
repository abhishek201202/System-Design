#include<iostream>
#include<vector>
#include<string>
#include "Date.h"
using namespace std;


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
