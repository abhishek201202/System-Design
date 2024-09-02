/*
This pattern acts as a bridge or intermediate between 2 incompatible interfaces.
*/
#include<bits/stdc++.h>
using namespace std;

// client interface
class Client {
public:
    virtual void request() const {
        cout << "Client: The default client's behavior.\n";
    }
    virtual ~Client() = default;
};
// adaptee class
class Adaptee {
public:
    void specificRequest() const {
        cout << "Adaptee: The specific request.\n";
    }
};
// adapter class
class Adapter : public Client {
private:
    Adaptee* adaptee;
public:
    Adapter(Adaptee* a) : adaptee(a) {}
    void request() const override {
        cout << "Adapter: Translating request to specific request.\n";
        adaptee->specificRequest();
    }
    ~Adapter() {
        delete adaptee;
    }
};
// client
int main() {
    Adaptee* adaptee = new Adaptee();
    Client* client = new Adapter(adaptee);
    client->request();  // The client calls the method defined in the Client interface
    delete client;
    return 0;
}

