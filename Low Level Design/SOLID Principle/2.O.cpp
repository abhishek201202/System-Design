/*
Open for extension but closed for modification
*/

#include<bits/stdc++.h>
using namespace std;

// Not following Open/closed principle
class InvoiceDao {
    Invoice invoice;
public:
    InvoiceDao(Invoice invoice) {
        this->invoice = invoice;
    }

    void saveToDB() {
        // save to DB
    }

    // new requested feature
    void saveToFile() {
        // save to File
    }
};



// Following Open/closed principle
class InvoiceDao {
public:
    virtual void save(Invoice invoice);
};

class DatabaseInvoiceDao: public InvoiceDao {
public:
    void save(Invoice invoice) {
        // save to db
    }
};

class FileInvoiceDao: public InvoiceDao {
public:
    void save(Invoice invoice) {
        // save to file
    }
}
