/*
Turns requests (commands) into objects, allowing you to either parameterize or queue them. 
This will help to decouple the request sender and request.
*/
#include<bits/stdc++.h>
#include<iostream>
#include<stack>
using namespace std;

// Receiver class
class Light {
private:
    bool isOn = false;
public:
    void turnOn() {
        isOn = true;
        cout << "The light is on." << endl;
    }
    void turnOff() {
        isOn = false;
        cout << "The light is off." << endl;
    }
    bool getState() const {
        return isOn;
    }
};

// Command interface
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
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
    void undo() override {
        light->turnOff();
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
    void undo() override {
        light->turnOn();
    }
};

// Invoker class with undo/redo functionality
class RemoteControl {
private:
    stack<Command*> commandHistory;
    stack<Command*> redoStack;
public:
    void executeCommand(Command* command) {
        command->execute();
        commandHistory.push(command);
        // Clear the redo stack after a new command is executed
        while (!redoStack.empty()) {
            redoStack.pop();
        }
    }
    void undo() {
        if (!commandHistory.empty()) {
            Command* command = commandHistory.top();
            command->undo();
            commandHistory.pop();
            redoStack.push(command);
        } else {
            cout << "Nothing to undo." << endl;
        }
    }
    void redo() {
        if (!redoStack.empty()) {
            Command* command = redoStack.top();
            command->execute();
            redoStack.pop();
            commandHistory.push(command);
        } else {
            cout << "Nothing to redo." << endl;
        }
    }
};

int main() {
    // Receiver
    Light livingRoomLight;

    // Invoker
    RemoteControl remote;

    // Turn the light on
    remote.executeCommand(new TurnOnCommand(&livingRoomLight));
    // Turn the light off
    remote.executeCommand(new TurnOnCommand(&livingRoomLight));
    // Undo the last command (which was turning off the light)
    remote.undo();
    // Redo the last undone command (which was turning off the light)
    remote.redo();

    return 0;
}
