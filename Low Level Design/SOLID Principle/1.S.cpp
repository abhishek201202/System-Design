/*
S: Single Responsibility Principle
A class should have only 1 reason to change
*/


#include<bits/stdc++.h>
using namespace std;

class Marker {
public:
    string name, color;
    int year, price;
    Marker(string name, string color, int year, int price) {
        this->name = name;
        this->color = color;
        this->year = year;
        this->price = price;
    }
};


// Not following Single Responsibility Principle
class Invoice {
    Marker marker;
    int qty;
public: 
    Invoice(Marker marker, int qty) {
        this->marker = marker;
        this->qty = qty;
    }

    int calculateTotal() {
        int price = marker.price * this->qty;
        return price;
    }

    void saveToDB() {
        // save to DB
    }

    void print() {
        // print invoice
    }
};

// Following Single Responsibility Principle
class Invoice {
    Marker marker;
    int qty;
public:
    Invoice(Marker marker, int qty) {
        this->marker = marker;
        this->qty = qty;
    }

    int calculateTotal() {
        int price = marker.price * this->qty;
        return price;
    }
};

class InvoiceDao {
    Invoice invoice;
public:
    InvoiceDao(Invoice invoice) {
        this->invoice = invoice;
    }

    void saveToDB() {
        // save to DB
    }
};

class InvoicePrinter {
    Invoice invoice;
    InvoicePrinter(Invoice invoice) {
        this->invoice = invoice;
    }

    void print() {
        // print invoice
    }
};

