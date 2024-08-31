/*
FR - 
1. memory issue
2. add/delete delete character anywhere in the doc
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;


// Flyweight class
class Character {
private:
    char c_;
    string font_;
    int size_;
    string color_;

public:
    Character(char c, const string& font, int size, const string& color) : c_(c), font_(font), size_(size), color_(color) {}
    void Display() const {
        cout << "Character: " << c_ << ", Font: " << font_ << ", Size: " << size_ << ", Color: " << color_ << endl;
    }
};

// Flyweight Factory class
class CharacterFactory {
private:
    unordered_map<string, shared_ptr<Character>> characters_;

public:
    shared_ptr<Character> GetCharacter(char c, const string& font, int size, const string& color) {
        string key = string(1, c) + font + to_string(size) + color;
        
        if (characters_.find(key) == characters_.end()) {
            characters_[key] = make_shared<Character>(c, font, size, color);
        }
        
        return characters_[key];
    }
};

class Document {
private:
    vector<shared_ptr<Character>> document; // for delete we can make it linked list
public:
    void addCharacter(shared_ptr<Character> ch) {
        document.push_back(ch);
    }
    void printDocument() {
        for(shared_ptr<Character> ch: document) {
            ch -> Display();
        }
    }
};

// Client code
int main() {
    CharacterFactory factory;
    Document document;
    
    document.addCharacter(factory.GetCharacter('H', "Arial", 12, "Black"));
    document.addCharacter(factory.GetCharacter('e', "Arial", 12, "Black"));
    document.addCharacter(factory.GetCharacter('l', "Arial", 12, "Black"));
    document.addCharacter(factory.GetCharacter('l', "Arial", 12, "Black"));
    document.addCharacter(factory.GetCharacter('o', "Arial", 12, "Black"));
    
    document.addCharacter(factory.GetCharacter(' ', "Arial", 12, "Black"));
    
    document.addCharacter(factory.GetCharacter('W', "Arial", 12, "Black"));
    document.addCharacter(factory.GetCharacter('o', "Arial", 12, "Black"));
    document.addCharacter(factory.GetCharacter('r', "Arial", 12, "Black"));
    document.addCharacter(factory.GetCharacter('l', "Arial", 12, "Black"));
    document.addCharacter(factory.GetCharacter('d', "Arial", 12, "Black"));

    // Display the document
    document.printDocument();

    return 0;
}
