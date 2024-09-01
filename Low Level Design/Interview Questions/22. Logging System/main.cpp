/*
FR - 
1. log info, debug and error logs based on log type
*/

#include<bits/stdc++.h>
using namespace std;

// Abstract Logger
class Logger {
protected:
    shared_ptr<Logger> nextLogger;
public:
    void setNextLogger(shared_ptr<Logger> logger) {
        nextLogger = logger;
    }
    void logMessage(const string& messageType, const string& message) {
        if (this->handle(messageType, message)) {
            return; // Handled by this logger
        } else if (nextLogger) {
            nextLogger->logMessage(messageType, message);
        }
    }
    virtual bool handle(const string& messageType, const string& message) = 0;
};

// Concrete Logger for Info messages
class InfoLogger : public Logger {
public:
    bool handle(const string& messageType, const string& message) override {
        if (messageType == "INFO") {
            cout << "InfoLogger: " << message << endl;
            return true;
        }
        return false;
    }
};

// Concrete Logger for Debug messages
class DebugLogger : public Logger {
public:
    bool handle(const string& messageType, const string& message) override {
        if (messageType == "DEBUG") {
            cout << "DebugLogger: " << message << endl;
            return true;
        }
        return false;
    }
};

// Concrete Logger for Error messages
class ErrorLogger : public Logger {
public:
    bool handle(const string& messageType, const string& message) override {
        if (messageType == "ERROR") {
            cerr << "ErrorLogger: " << message << endl;
            return true;
        }
        return false;
    }
};

// Client code
int main() {
    // Create loggers
    auto infoLogger = make_shared<InfoLogger>();
    auto debugLogger = make_shared<DebugLogger>();
    auto errorLogger = make_shared<ErrorLogger>();

    // Set up the chain: Info -> Debug -> Error
    infoLogger->setNextLogger(debugLogger);
    debugLogger->setNextLogger(errorLogger);

    // Log messages with different types
    infoLogger->logMessage("INFO", "This is an info message");   // InfoLogger will handle this
    infoLogger->logMessage("DEBUG", "This is a debug message");  // DebugLogger will handle this
    infoLogger->logMessage("ERROR", "This is an error message"); // ErrorLogger will handle this

    return 0;
}
