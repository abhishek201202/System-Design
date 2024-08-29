/*
This pattern helps in scenarios where we have an object inside an object (tree like structure).
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Component: The base class that defines the common interface for both files and folders
class FileSystemItem {
public:
    virtual ~FileSystemItem() = default;
    virtual string getName() const = 0;
    virtual int getSize() const = 0;
    virtual void print(const string& indentation = "") const = 0;
};

// Leaf: Represents a single file
class File : public FileSystemItem {
private:
    string name;
    int size;
public:
    File(const string& name, int size) : name(name), size(size) {}
    string getName() const override { return name; }
    int getSize() const override { return size; }

    void print(const string& indentation = "") const override {
        cout << indentation << getName() << " (File, " << getSize() << " KB)" << endl;
    }
};

// Composite: Represents a folder that can contain files and/or other folders
class Folder : public FileSystemItem {
private:
    string name;
    vector<shared_ptr<FileSystemItem>> items;
public:
    Folder(const string& name) : name(name) {}
    string getName() const override {
        return name;
    }
    void add(shared_ptr<FileSystemItem> item) {
        items.push_back(item);
    }
    void remove(shared_ptr<FileSystemItem> item) {
      items.erase(std::remove(items.begin(), items.end(), item), items.end());
    }
    int getSize() const override {
        int totalSize = 0;
        for (const auto& item : items) {
            totalSize += item->getSize();
        }
        return totalSize;
    }
    void print(const string& indentation = "") const override {
        cout << indentation << getName() << " (Folder, " << getSize() << " KB)" << endl;
        for (const auto& item : items) {
            item->print(indentation + "  ");
        }
    }
};

// Usage
int main() {
    auto file1 = make_shared<File>("File1.txt", 10);
    auto file2 = make_shared<File>("File2.txt", 20);
    auto file3 = make_shared<File>("File3.txt", 30);

    auto folder1 = make_shared<Folder>("Folder1");
    folder1->add(file1);
    folder1->add(file2);

    auto folder2 = make_shared<Folder>("Folder2");
    folder2->add(file3);

    auto rootFolder = make_shared<Folder>("RootFolder");
    rootFolder->add(folder1);
    rootFolder->add(folder2);

    rootFolder->print();

    return 0;
}
