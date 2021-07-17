#include<bits/stdc++.h>
using namespace std;



class ParkingLot {
	vector<ParkingFloor> parkingFloors;
	vector<Entrance> entrances;
	vector<Exit> exits;
	Address address;
	string parkingLotName;

public:
	bool isParkingSpaceAvailableForVehicle(Vehicle vehicle);
	bool updateParkingAttendant(ParkingAttendant parkingAttendant, int gateId);
};



class ParkingFloor {
	int levelId;
	bool isFull;
	vector<ParkingSpace> parkingSpace;
	ParkingDisplayBoard parkingDisplayBoard;
};



class Gate {
	int gateId;
	ParkingAttendant parkingAttendant;
};



class Entrance: public Gate {
public:
	ParkingTicket getParkingTicket(Vehicle vehicle);
};


class Exit: public Gate {
public:
	ParkingTicket payForParking(ParkingTicket parkingTicket, PaymentType paymentType);		
};

class Address {
	string country;
	string state;
	string city;
	string street;
	string pincode;
};




class ParkingSpace {
	int spaceId;
	bool isFree;
	double costPerHour;
	Vehicle vehicle;
	ParkingSpaceType parkingSpaceType;
};




class ParkingDisplayBoard {
	map<ParkingSpaceType, int> freeSpotsAvailableMap;
public:
	void updateFreeSpotsAvailable(ParkingSpaceType parkingSpaceType, int spaces);
};



class Account {
	string name;
	string email;
	string password;
	string empId;
	Address address;
};


class Admin: public Account {
public:
	bool addParkingFloor(ParkingLot parkingLot, ParkingFloor floor);
	bool addParkingSpace(ParkingFloor floor, ParkingSpace parkingSpace);
	bool addParkingDisplayBoard(ParkingFloor floor, ParkingDisplayBoard parkingDisplayBoard);
};



class ParkingAttendant: public Account {
	Payment paymentService;
public:
	bool processVehicleEntry(Vehicle vehicle);
	PaymentInfo processPayment(ParkingTicket parkingTicket, PaymentType paymentType);
};


class Vehicle {
	string licenseNumber;
	VehicleType vehicleType;
	ParkingTicket parkingTicket;
	PaymentInfo paymentInfo;
};



class ParkingTicket {
	int ticketId;
	int levelId;
	int spaceId;
	Date vehicleEntryDateTime;
	Date vehicleExitDateTime;
	ParkingSpaceType parkingSpaceType;
	double totalCost;
	ParkingTicketStatus parkingTicketStatus;

public:
	void updateTotalCost();
	void updateVehicleExitTime(Date vehicleExitDateTime);
};


enum PaymentType {
	CASH, CREDIT_CARD, DEBIT_CARD, UPI
};


enum ParkingSpaceType {
	BIKE_PARKING, CAR_PARKING, TRUCK_PARKING
};


class Payment {
public:
	PaymentInfo makePayment(ParkingTicket parkingTicket, PaymentType paymentType);
};


class PaymentInfo {
	double amount;
	Date paymentDate;
	int transactionId;
	ParkingTicket parkingTicket;
	PaymentStatus paymentStatus;
};

enum VehicleType {
	BIKE, CAR, TRUCK
};

enum ParkingTicketStatus {
	PAID, ACTIVE
};

enum PaymentStatus {
	UNPAID, PENDING, COMPLETED, DECLINED, CANCELLED, REFUNDED
};






int32_t main(){

}