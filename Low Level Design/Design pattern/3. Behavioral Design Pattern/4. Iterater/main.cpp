/*
It provides a way to access elements of a collection sequentially without exposing the underlying representation of the collection.
*/
#include<bits/stdc++.h>
using namespace std;

// iterater interface
class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual int next() = 0;
};

// concrete iterator
class ArrayIterator : public Iterator {
private:
    const int* data;
    int size;
    int index;
public:
    ArrayIterator(const int* data, int size) : data(data), size(size), index(0) {}
    bool hasNext() const override {
        return index < size;
    }
    int next() override {
        return data[index++];
    }
};

// aggregate interface 
class Aggregate {
public:
    virtual Iterator* createIterator() const = 0;
};

// concrete aggregater 
class ArrayAggregate : public Aggregate {
private:
    int* data;
    int size;
public:
    ArrayAggregate(int* data, int size) : data(data), size(size) {}
    Iterator* createIterator() const override {
        return new ArrayIterator(data, size);
    }
    ~ArrayAggregate() {
        delete[] data;
    }
};

// client
int main() {
    int* data = new int[5]{1, 2, 3, 4, 5};
    ArrayAggregate aggregate(data, 5);
    Iterator* iterator = aggregate.createIterator();
    while (iterator->hasNext()) {
        cout << iterator->next() << " ";
    }
    cout << endl;
}
