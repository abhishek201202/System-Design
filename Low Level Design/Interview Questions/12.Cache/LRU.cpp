#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache {
public:
    
    class DLL{
        public:
        int val;
        DLL *next , *prev;
        DLL(int val){
            this -> val = val;
            next = prev = NULL;
        }
    };
    
    DLL *head , *tail;
    unordered_map<int , DLL*> id;
    unordered_map<DLL* , int> Rid;
    unordered_map<int , int> V;
    int T , C;
    bool okk ;
    
    LRUCache(int capacity) {
        T = capacity;
        C = 0;
        okk = true;
        head = tail = NULL;
    }
    
    void put_to_front(int key){
        DLL *pos = id[key];
        if(pos == tail){
            tail = tail -> prev;
            tail -> next = NULL;
            pos -> next = head;
            pos -> prev = NULL;
            head -> prev = pos;
        }else if(pos != head){
            DLL *P = pos -> prev;
            DLL *N = pos -> next;
            P -> next = N;
            N -> prev = P;
            pos -> next = head;
            head -> prev = pos;
        }     
        head = pos;
    }
    
    int get(int key) {
        if(!V.count(key)) return -1;
        if(head == tail) return V[key];
        put_to_front(key);
        return V[key];
    }
    
    void put(int key, int value){
        if(V.count(key)){
            put_to_front(key);
            V[key] = value;
            return;
        }
     
        DLL *N = new DLL(value);
        V[key] = value;
        id[key] = N;
        Rid[N] = key;
        
        
        if(T == C){
            DLL *pos = tail;
            tail = tail -> prev;
            tail -> next = NULL;
            
            V.erase(Rid[pos]);
            id.erase(Rid[pos]);
            Rid.erase(pos);
        }else{
            C++;
        }
        
        if(tail == NULL){
            head = tail = N;
            tail -> prev = head;
        }else{
            N -> next = head;
            head -> prev = N;
            head = N;
            if(head != tail && okk){
                tail -> prev = head;
                okk = false;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){

}