/*
FR - 
1. memory issue
2. add/delete delete character anywhere in the doc
3. print document
*/

#include<bits/stdc++.h>
using namespace std;

class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;
};

class InsertTextCommand : public Command {
private:
    string text;
    int position;
    string& document;

public:
    InsertTextCommand(string txt, int pos, string& doc)
        : text(txt), position(pos), document(doc) {}

    void execute() override {
        document.insert(position, text);
    }

    void undo() override {
        document.erase(position, text.size());
    }

    void redo() override {
        execute();
    }
};

class DeleteTextCommand : public Command {
private:
    string deletedText;
    int position;
    string& document;

public:
    DeleteTextCommand(int pos, int len, string& doc)
        : position(pos), document(doc) {
        deletedText = document.substr(pos, len);
    }

    void execute() override {
        document.erase(position, deletedText.size());
    }

    void undo() override {
        document.insert(position, deletedText);
    }

    void redo() override {
        execute();
    }
};

class CommandManager {
private:
    stack<Command*> undoStack;
    stack<Command*> redoStack;

public:
    void executeCommand(Command* command) {
        command->execute();
        undoStack.push(command);
        // Clear the redo stack when a new command is executed
        while (!redoStack.empty()) {
            delete redoStack.top();
            redoStack.pop();
        }
    }

    void undo() {
        if (!undoStack.empty()) {
            Command* command = undoStack.top();
            undoStack.pop();
            command->undo();
            redoStack.push(command);
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            Command* command = redoStack.top();
            redoStack.pop();
            command->redo();
            undoStack.push(command);
        }
    }

    ~CommandManager() {
        while (!undoStack.empty()) {
            delete undoStack.top();
            undoStack.pop();
        }
        while (!redoStack.empty()) {
            delete redoStack.top();
            redoStack.pop();
        }
    }
};

int main() {
    string document;
    CommandManager manager;

    // Insert "Hello"
    manager.executeCommand(new InsertTextCommand("Hello", 0, document));
    cout << "Document after insert: " << document << endl;

    // Insert " World"
    manager.executeCommand(new InsertTextCommand(" World", 5, document));
    cout << "Document after insert: " << document << endl;

    // Undo last command
    manager.undo();
    cout << "Document after undo: " << document << endl;

    // Redo last undo
    manager.redo();
    cout << "Document after redo: " << document << endl;

    // Delete "World"
    manager.executeCommand(new DeleteTextCommand(5, 6, document));
    cout << "Document after delete: " << document << endl;

    // Undo delete
    manager.undo();
    cout << "Document after undo delete: " << document << endl;

    return 0;
}
