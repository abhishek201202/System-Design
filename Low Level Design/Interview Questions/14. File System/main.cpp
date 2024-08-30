/*
FR - 
1. It can have file, folder and file can have sub folder.
2. ls command
3. search file with extension, name, size
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Component: The base class for files and directories
class FileSystemEntity {
protected:
    string name;
public:
    FileSystemEntity(const string& name) : name(name) {}
    virtual ~FileSystemEntity() {}
    virtual void display(int indent = 0) const = 0;
    virtual void add(shared_ptr<FileSystemEntity> entity) {
        throw runtime_error("Cannot add to this entity.");
    }
};

// Leaf: Represents files in the file system
class File : public FileSystemEntity {
public:
    File(const string& name) : FileSystemEntity(name) {}
    void display(int indent = 0) const override {
        cout << string(indent, ' ') << "- " << name << " (File)\n";
    }
};


// Composite: Represents directories in the file system
class Directory : public FileSystemEntity {
private:
    vector<shared_ptr<FileSystemEntity>> children;
public:
    Directory(const string& name) : FileSystemEntity(name) {}
    void add(shared_ptr<FileSystemEntity> entity) override {
        children.push_back(entity);
    }

    void display(int indent = 0) const override {
        cout << string(indent, ' ') << "+ " << name << " (Directory)\n";
        for (const auto& child : children) {
            child->display(indent + 2);
        }
    }
};

int main() {
    // Create files
    shared_ptr<FileSystemEntity> file1 = make_shared<File>("file1.txt");
    shared_ptr<FileSystemEntity> file2 = make_shared<File>("file2.txt");

    // Create a directory and add files to it
    shared_ptr<Directory> dir1 = make_shared<Directory>("Documents");
    dir1->add(file1);
    dir1->add(file2);

    // Create another directory
    shared_ptr<Directory> dir2 = make_shared<Directory>("Pictures");

    // Create the root directory and add the other directories to it
    shared_ptr<Directory> root = make_shared<Directory>("root");
    root->add(dir1);
    root->add(dir2);
    root->add(make_shared<File>("readme.txt"));

    // Display the entire file system
    root->display();

    return 0;
}
