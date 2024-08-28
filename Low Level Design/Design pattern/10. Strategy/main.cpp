/*
It helps to define multiple algorithms for the task and we can select any algorithm depending on the situation.
*/
#include<bits/stdc++.h>
using namespace std;

// strategy interface
class SortStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0;
    virtual ~SortStrategy() {}
};

// concrete strategies
class BubbleSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        // do something
    }
};
class QuickSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        // do something
    }
};

// context
class SortingContext {
private:
    SortStrategy* strategy;
public:
    SortingContext(SortStrategy* initialStrategy) : strategy(initialStrategy) {}
    void setStrategy(SortStrategy* newStrategy) {
        strategy = newStrategy;
    }
    void sortData(std::vector<int>& data) {
        strategy->sort(data);
    }
};


