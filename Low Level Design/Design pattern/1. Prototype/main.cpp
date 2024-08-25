#include<bits/stdc++.h>
using namespace std;

// Not following Prototype Pattern
class NetworkConnection {
private:
    string ip, importantaData;
    vector<string> servers;
public:
    void loadImportantData() {
        this -> importantaData = "very very imp data.....";
        // it takes 5 minutes
    }
    void setIp(string ip) {
        this->ip = ip;
    }
};

// Following Prototype Pattern
class NetworkConnectionInterface {
    public:
    virtual NetworkConnectionInterface clone();
};

class NetworkConnectionPrototype: public NetworkConnectionInterface {
private:
    string ip, importantaData;
    vector<string> servers;
public:
    NetworkConnectionPrototype() {};
    NetworkConnectionPrototype(const NetworkConnectionPrototype& obj) {
        // deep copy
        this->ip = obj.ip;
        this->importantaData = obj.importantaData;
        for(string server: servers) {
            this->servers.push_back(server);
        }
    }
    NetworkConnectionInterface& clone() const {
        return NetworkConnectionPrototype(*this);
    }
    void loadImportantData() {
        this -> importantaData = "very very imp data.....";
        // it takes 5 minutes=
    }
    void setIp(string ip) {
        this->ip = ip;
    }
};


int main (){
    NetworkConnection n1;
    n1.setIp("10.10.10.10");
    n1.loadImportantData(); // it takes 5 minutes

    // shallow copied object
    NetworkConnection n2(n1);

    NetworkConnectionPrototype n3;
    n3.setIp("11.11.11.11");
    n3.loadImportantData(); // it takes 5 minutes

    // deep cloned obj
    NetworkConnectionInterface n4 = n3.clone(); 
}