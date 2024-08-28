/*
In this object (observable) maintains a list of its dependent(observers) and notifies them of any change in its state.
*/
#include<bits/stdc++.h>
using namespace std;

// observer interface
class Observer {
public:
    virtual void update(float temperature) = 0;
};

// subject interface
class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
};

// concrete subject
class TemperatureSensor : public Subject {
private:
    std::vector<Observer*> observers;
    float temperature;
public:
    void setTemperature(float temp) {
        temperature = temp;
        notify();
    }
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }
    void detach(Observer* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }
    void notify() override {
        for (auto* observer : observers) {
            observer->update(temperature);
        }
    }
};

// concrete observer
class TemperatureDisplay : public Observer {
private:
    std::string name;
public:
    TemperatureDisplay(const std::string& displayName) : name(displayName) {}
    void update(float temperature) override {
        std::cout << name << " updated temperature: " << temperature << "°C\n";
    }
};



