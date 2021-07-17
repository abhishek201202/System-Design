#include<bits/stdc++.h>
using namespace std;


class ATM {
	int atmID;
	Address location;

	CashDispenser cashDispenser;
	Screen screen;
	CardReader cardReader;
	Keypad keypad;
	CashDeposit cashDeposit;
	ChequeDeposit chequeDeposit;

	BankService bankService;
};


class Address {
	int pincode;
	string street;
	string city;
	string state;
	string country;
};



class CashDispenser {
	map<CashType, vector<Cash>> cashAvailable;
public:
	void dispenseCash(int amount);
};



enum CashType {
	FIFTY, HUNDRED, FIVEHUNDRED
};

class Cash {
	CashType cashType;
	string serialNumber;
};


class Screen {
public:
	void diplay(string message);
};



class CardReader {
public:
	CardInfo fetchCardDetails();
};


class CardInfo {
	CardType cardType;
	Bank bank;
	string cardNumber;
	Date expiryDate;
	int cvv;
	float withdrawLimit;
};


enum CardType {
	DEBIT, CREDIT
};


class Keypad {
public:
	string getInput();
};




class Bank {
	string name;
	Address location;
	vector<ATM> atmList;
};


class BankService {
public:
	virtual bool isValidUser(string pin, CardInfo cardInfo);
	virtual Customer getCustomerDetails(CardInfo cardInfo);
	virtual TransactionDetail executeTransaction(Transaction transactionInfo, Customer customer);
};

class BankA: public BankService {
public:
	bool isValidUser(string pin, CardInfo);
	Customer getCustomerDetails(CardInfo cardInfo);
	TransactionDetail executeTransaction(Transaction transactionInfo, Customer, customer);
};
class BankB: public BankService {
public:
	bool isValidUser(string pin, CardInfo);
	Customer getCustomerDetails(CardInfo cardInfo);
	TransactionDetail executeTransaction(Transaction transactionInfo, Customer, customer);
};


class BankServiceFactory {
public:
	BankService getBankServiceObject(CardInfo cardInfo);
};


class Customer {
	string firstName;
	string lastName;
	CardInfo cardInfo;
	Account account;
	BankService bankServiceObj;
	CustomerStatus customerStatus;
};



class Account {
	string accoutNumber;
	float availableBalance;
};



enum CustomerStatus {
	BLOCKED, ACTIVE, CLOSED
};


class Transaction {
	int transactionId;
	string sourceAccount;
	Date transactionDate;
};


class Deposit: public Transaction {
	float amount;
};

class ChequeDeposit: public Deposit {
public:
	Cheque getCheque();
};

class CashDeposit: public Deposit {
public:
	vector<Cash> getCash();
};


class Withdraw: public Transaction {
	float amount;
};


class Transfer: public Transaction {
	string destAccount;
	float amount;
};



class TransactionDetail {
	TransactionStatus transactionStatus;
	string sourceAccountNumber;
	Date transactionDate;
	TransactionType transactionType;
	int transactionId;
};

enum TransactionStatus {
	PENDING, CANCELLED, SUCCESS, ERROR
};

enum TransactionType {
	WITHDRAW, DEPOSIT, TRANSFER
};

int32_t main(){

}