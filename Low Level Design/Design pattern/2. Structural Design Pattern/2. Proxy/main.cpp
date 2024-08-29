/*
This pattern helps us to provide control access to original object.
*/
#include<bits/stdc++.h>
using namespace std;

class EmployeeDAO {
private:
    virtual void create();
};

class EmployeeDaoImplementation: public EmployeeDAO {
private:
    void create() {
        // some logic here
    }
};

class EmployeeDaoProxy: public EmployeeDAO {
private:
    EmployeeDAO obj;
    EmployeeDaoProxy() {
        obj = new EmployeeDaoImplementation();
    }
    void create() {
        if (ADMIN) {
            obj.create();
        } else {
            throw new exception("error...");
        }
    }
};


