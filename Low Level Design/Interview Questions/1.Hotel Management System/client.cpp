#include<iostream>
#include<vector>
#include<algorithm>
#include "Person.h"
#include "Room.h"
#include "Account.h"
#include "services.h"
#include "Date.h"
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


int main(){

}

