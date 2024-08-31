/*
Turns requests (commands) into objects, allowing you to either parameterize or queue them. 
This will help to decouple the request sender and request.
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Receiver class
class Light {
public:
    void turnOn() {
        cout << "The light is on." << endl;
    }
    void turnOff() {
        cout << "The light is off." << endl;
    }
};

// Command interface
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

// Concrete Command to turn on the light
class TurnOnCommand : public Command {
private:
    Light* light;
public:
    TurnOnCommand(Light* light) : light(light) {}
    void execute() override {
        light->turnOn();
    }
};

// Concrete Command to turn off the light
class TurnOffCommand : public Command {
private:
    Light* light;
public:
    TurnOffCommand(Light* light) : light(light) {}
    void execute() override {
        light->turnOff();
    }
};


// Invoker class
class RemoteControl {
private:
    Command* command;
public:
    void setCommand(Command* command) {
        this->command = command;
    }
    void pressButton() {
        if (command) {
            command->execute();
            command = nullptr;
        }
    }
};

int main() {
    // Receiver
    Light livingRoomLight;

    // Invoker
    RemoteControl remote;

    // Turn the light on
    remote.setCommand(new TurnOnCommand(&livingRoomLight));
    remote.pressButton();

    // Turn the light off
    remote.setCommand(new TurnOffCommand(&livingRoomLight));
    remote.pressButton();

    return 0;
}
