#include<iostream>
#include<vector>
#include<string>
using namespace std;

enum AccountStatus{
    ACTIVE, CLOSED, BLOCKED
};

class Account{
    string username;
    string password;
    AccountStatus accountStatus;
};
