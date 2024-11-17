/**
 * Custom Comparator with Priority Queue
 * If you want a custom priority order, you can define a 
 * comparator function or struct. For example, 
 * if you’re working with a custom class and want 
 * the priority queue to prioritize based on a specific attribute, 
 * you can define a comparator.
 */

#include <iostream>
#include <queue>
#include <vector>

struct Task {
    int id;
    int priority;
    // Constructor
    Task(int i, int p) : id(i), priority(p) {}
};

// Comparator for min-heap based on priority
struct CompareTask {
    bool operator()(Task const& t1, Task const& t2) {
        return t1.priority > t2.priority;  // Higher priority number means lower priority
    }
};

int main() {
    std::priority_queue<Task, std::vector<Task>, CompareTask> taskQueue;

    taskQueue.push(Task(1, 3));  // Task with priority 3
    taskQueue.push(Task(2, 1));  // Task with priority 1
    taskQueue.push(Task(3, 2));  // Task with priority 2

    // Process tasks by priority
    while (!taskQueue.empty()) {
        Task t = taskQueue.top();
        std::cout << "Task ID: " << t.id << " with Priority: " << t.priority << std::endl;
        taskQueue.pop();
    }
    // Expected Output:
    // Task ID: 2 with Priority: 1
    // Task ID: 3 with Priority: 2
    // Task ID: 1 with Priority: 3

    return 0;
}
//
//Key Points

//    Priority queues are implemented as heaps, providing efficient priority-based ordering.
//    The default behavior is a max-heap, but it can be configured as a min-heap with custom comparators.
//    priority_queue is useful in situations where you need to access elements based on a priority order, 
//    such as task scheduling or pathfinding algorithms (like Dijkstra's algorithm).
//
