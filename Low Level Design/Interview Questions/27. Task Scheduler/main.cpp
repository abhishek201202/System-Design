#include<bits/stdc++.h>
using namespace std;

/*
Task
------------


TaskQueue
------------


PriorityTaskQueue (TaskQueue)
------------


Scheduler
------------
TaskQueue *taskQueue;


PriorityBasedScheduler (Scheduler)
------------


TaskManager
------------
Scheduler *scheduler;


*/

// Task Class
class Task {
public:
    string taskID;
    function<void()> action;
    chrono::system_clock::time_point scheduleTime;
    bool isRecurring;
    chrono::seconds interval;
    Task(const string& id, function<void()> act, chrono::system_clock::time_point schedTime, bool recurring = false, chrono::seconds inter = chrono::seconds(0)) : taskID(id), action(act), scheduleTime(schedTime), isRecurring(recurring), interval(inter) {}
    void execute() const {
        action();
    }
    chrono::system_clock::time_point getNextExecutionTime() const {
        if (isRecurring) {
            return scheduleTime + interval;
        }
        return scheduleTime;
    }
};

// TaskQueue Class
class TaskQueue {
private:
    priority_queue<pair<chrono::system_clock::time_point, Task>, vector<pair<chrono::system_clock::time_point, Task>>, greater<>> tasks;
public:
    void enqueue(const Task& task) {
        tasks.push({task.scheduleTime, task});
    }
    Task dequeue() {
        auto top = tasks.top();
        tasks.pop();
        return top.second;
    }
    Task peekNextTask() const {
        return tasks.top().second;
    }
    bool isEmpty() const {
        return tasks.empty();
    }
};

// Timer Class
class Timer {
public:
    static void sleepFor(int milliseconds) {
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
    }

    static chrono::system_clock::time_point getCurrentTime() {
        return chrono::system_clock::now();
    }
};

// Scheduler Class
class Scheduler {
private:
    TaskQueue taskQueue;
public:
    void addTask(const Task& task) {
        taskQueue.enqueue(task);
    }
    void removeTask(const string& taskID) {
        // Removal from priority_queue is not trivial. A more complex implementation would be required for removal.
        // For simplicity, we'll assume tasks are not removed once added.
    }
    void run() {
        while (!taskQueue.isEmpty()) {
            Task task = taskQueue.peekNextTask();
            auto now = Timer::getCurrentTime();
            auto nextExecutionTime = task.getNextExecutionTime();

            if (now < nextExecutionTime) {
                Timer::sleepFor(chrono::duration_cast<chrono::milliseconds>(nextExecutionTime - now).count());
            }

            task.execute();

            if (task.isRecurring) {
                task.scheduleTime = task.getNextExecutionTime();
                taskQueue.enqueue(task);
            } else {
                taskQueue.dequeue();
            }
        }
    }
};

// TaskManager Class
class TaskManager {
private:
    Scheduler scheduler;
public:
    void scheduleTask(const Task& task) {
        scheduler.addTask(task);
    }
    void cancelTask(const string& taskID) {
        scheduler.removeTask(taskID);
    }
    void start() {
        scheduler.run();
    }
};

// Example usage
void exampleTask() {
    cout << "Task executed at " << time(0) << endl;
}

int main() {
    TaskManager taskManager;

    // Create a recurring task to be executed every 5 seconds
    Task recurringTask("task001", exampleTask, Timer::getCurrentTime() + chrono::seconds(5), true, chrono::seconds(5));

    // Schedule the task
    taskManager.scheduleTask(recurringTask);

    // Start the task scheduler
    taskManager.start();

    return 0;
}
