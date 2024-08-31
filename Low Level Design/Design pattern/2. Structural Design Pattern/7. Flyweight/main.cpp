/*
This pattern helps to reduce the memory usage by sharing data among multiple objects.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// The Flyweight class that contains the intrinsic state
class TreeType {
private:
    string name; // intrinsic data
    string texture; // intrinsic data
public:
    TreeType(const string& name, const string& texture) : name(name), texture(texture) {}
    void display(int x, int y) const { // extrinsic data
        cout << "Tree [Type: " << name << ", Texture: " << texture << "] at (" << x << ", " << y << ")\n";
    }
};

// The Flyweight Factory class
class TreeFactory {
private:
    unordered_map<string, TreeType*> treeTypes;
public:
    ~TreeFactory() {
        for (auto pair : treeTypes) delete pair.second;
    }
    TreeType* getTreeType(const string& name, const string& texture) {
        string key = name + "_" + texture;
        if (treeTypes.find(key) == treeTypes.end()) {
            treeTypes[key] = new TreeType(name, texture);
        }
        return treeTypes[key];
    }
};

// The Context class that stores the extrinsic state (position)
class Tree {
private:
    int x, y;
    TreeType* type;

public:
    Tree(int x, int y, TreeType* type) : x(x), y(y), type(type) {}
    
    void display() const {
        type->display(x, y);
    }
};

// The Forest class that contains many trees
class Forest {
private:
    vector<Tree> trees;
    TreeFactory treeFactory;

public:
    void plantTree(int x, int y, const string& name, const string& texture) {
        TreeType* type = treeFactory.getTreeType(name, texture);
        trees.emplace_back(x, y, type);
    }
    
    void display() const {
        for (const auto& tree : trees) {
            tree.display();
        }
    }
};

int main() {
    Forest forest;
    forest.plantTree(10, 20, "Oak", "Green Leaves");
    forest.plantTree(15, 25, "Pine", "Long Leaves");
    forest.plantTree(10, 20, "Oak", "Green Leaves");  // Same type and texture

    forest.display();

    return 0;
}
