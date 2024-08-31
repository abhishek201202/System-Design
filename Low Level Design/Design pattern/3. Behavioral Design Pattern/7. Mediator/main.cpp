/*
Use Cases - 
1. Chat application
2. Online Auction System
3. Airline Management System
*/

#include<bits/stdc++.h>
using namespace std;


// Colleague class
class User {
private:
    string name;
    ChatRoomMediator* mediator;
public:
    User(const string& name, ChatRoomMediator* mediator) : name(name), mediator(mediator) {}
    void sendMessage(const string& message) {
        mediator->showMessage(this, message);
    }
    string getName() const {
        return name;
    }
};

// Mediator interface
class ChatRoomMediator {
public:
    virtual void showMessage(User* user, const string& message) = 0;
    virtual ~ChatRoomMediator() = default;
};

// Concrete Mediator class
class ChatRoom : public ChatRoomMediator {
public:
    void showMessage(User* user, const string& message) override {
        cout << user->getName() << ": " << message << endl;
    }
};


int main() {
    // Create the mediator
    ChatRoom chatRoom;

    // Create colleagues (Users)
    User user1("Alice", &chatRoom);
    User user2("Bob", &chatRoom);

    // Users send messages through the mediator (ChatRoom)
    user1.sendMessage("Hi Bob!");
    user2.sendMessage("Hello Alice!");

    return 0;
}