/*
It is used when we have to create only 1 instance of the class.
*/
#include<bits/stdc++.h>
#include<mutex>
#include<thread>
using namespace std;
/*
4 methods to achieve this
1. Eager
2. Lazy
3. Synchronized
4. Double Locking (used in industry)
*/


// Lazy Method
class Singleton {
private:
    static Singleton* obj;
    Singleton(){};
    // Delete copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
    static Singleton* getInstance() {
        if(obj == nullptr) {
            obj = new Singleton();
        }
        return obj;
    }
};

// Syncronized Method
class Singleton {
private:
    static Singleton* obj;
    static mutex mtx;
    Singleton(){};
    // Delete copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
    static Singleton* getInstance() {
        lock_guard<mutex> lock(mtx); // Acquire lock
        // mutex will automatically unlock when the lock_guard goes out of the scope.
        if(obj == nullptr) {
            obj = new Singleton();
        }
        return obj;
    }
};

// Double Locking Method
class Singleton {
private:
    static Singleton* obj;
    static once_flag initInstanceFlag;
    Singleton(){};
    // Delete copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
    static Singleton* getInstance() {
        if(obj == nullptr) {
            call_once(initInstanceFlag, []() {
                if(obj == nullptr) {
                    obj = new Singleton();
                }
            });
        }
        return obj;
    }
};
