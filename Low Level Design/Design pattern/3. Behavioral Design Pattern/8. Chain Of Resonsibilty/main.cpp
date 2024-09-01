/*
Use Cases - 
1. ATM
2. Vending Machine
3. Logging System
*/
#include<bits/stdc++.h>
using namespace std;

// Abstract Handler
class SupportHandler {
protected:
    shared_ptr<SupportHandler> nextHandler;
public:
    void setNextHandler(shared_ptr<SupportHandler> handler) {
        nextHandler = handler;
    }
    virtual void handleRequest(const string& request, int severity) = 0;
};

// Concrete Handler for low severity
class LowLevelSupportHandler : public SupportHandler {
public:
    void handleRequest(const string& request, int severity) override {
        if (severity <= 1) {
            cout << "LowLevelSupportHandler: Handling request '" << request << "'\n";
        } else if (nextHandler) {
            nextHandler->handleRequest(request, severity);
        }
    }
};

// Concrete Handler for medium severity
class MediumLevelSupportHandler : public SupportHandler {
public:
    void handleRequest(const string& request, int severity) override {
        if (severity == 2) {
            cout << "MediumLevelSupportHandler: Handling request '" << request << "'\n";
        } else if (nextHandler) {
            nextHandler->handleRequest(request, severity);
        }
    }
};

// Concrete Handler for high severity
class HighLevelSupportHandler : public SupportHandler {
public:
    void handleRequest(const string& request, int severity) override {
        if (severity >= 3) {
            cout << "HighLevelSupportHandler: Handling request '" << request << "'\n";
        } else if (nextHandler) {
            nextHandler->handleRequest(request, severity);
        }
    }
};

// Client code
int main() {
    // Create handlers
    auto lowHandler = make_shared<LowLevelSupportHandler>();
    auto mediumHandler = make_shared<MediumLevelSupportHandler>();
    auto highHandler = make_shared<HighLevelSupportHandler>();

    // Set up chain of responsibility
    lowHandler->setNextHandler(mediumHandler);
    mediumHandler->setNextHandler(highHandler);

    // Client sends requests
    lowHandler->handleRequest("Reset password", 1); // Handled by LowLevelSupportHandler
    lowHandler->handleRequest("Reboot server", 2);  // Handled by MediumLevelSupportHandler
    lowHandler->handleRequest("Server down", 3);    // Handled by HighLevelSupportHandler

    return 0;
}
