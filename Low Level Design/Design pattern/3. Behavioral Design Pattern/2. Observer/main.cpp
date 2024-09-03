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

// concrete observer
class TemperatureDisplay : public Observer {
private:
    string name;
public:
    TemperatureDisplay(const string& displayName) : name(displayName) {}
    void update(float temperature) override {
        cout << name << " updated temperature: " << temperature << "°C\n";
    }
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
    vector<Observer*> observers;
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
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }
    void notify() override {
        for (auto* observer : observers) {
            observer->update(temperature);
        }
    }
};





