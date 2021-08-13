// Part 1 ->  https://www.youtube.com/watch?v=FKA2KgkkcqY
// Part 2 -> https://www.youtube.com/watch?v=bPkXQszkkpY

#include<iostream>
using namespace std;


class LogClient{
public:
    /* when a process start, it calls 'start' with processId */
    void start(string processId);

    /* when a same process ends, it calls 'end' with processId */
    void end(string processId);
    
    
    /* 
    polls the first log entry of a completed process sorted by the start time 
    of process in the below format 
    {processId} started at {startTime} and ended at {endTime} 
    
    process id = 1 --> 12, 15
    process id = 2 --> 8, 12
    process id = 3 --> 7, 19 
    
    {3} started at {7} and ended at {19}
    {2} started at {8} and ended at {12}
    {1} started at {12} and ended at {15}
    */
    void poll();
};



int main(){

}