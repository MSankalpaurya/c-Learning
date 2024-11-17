/**
 * TOPIC:Priority Queue
 * 
 * A priority queue is a data structure that stores elements such
 * that each element has a priority associated with it. In a
 * priority queue, elements are dequeued in order of their
 * priority instead of the order in which they were added. 
 * By default, the element with the highest priority is 
 * dequeued first.
 * 
 * In C++, the Standard Template Library (STL) provides a 
 * priority_queue class that supports this structure, with the 
 * following properties:
 * 
 * 1. Max-Heap (by default): The highest-priority (largest) element 
 *    is at the top
 * 2. Min-Heap (using a custom comparator): We can change the 
 *    behavior to prioritize the smallest element.
 * 
 * 
 * Key Operations in priority_queue

    push(x): Inserts the element x into the queue.
    pop(): Removes the highest-priority element (top element).
    top(): Accesses the highest-priority element without removing it.
    empty(): Checks if the queue is empty.
    size(): Returns the number of elements in the queue.
 */

// Example: Using priority_queue as a Max-Heap

//In a max-heap, the largest element has the highest priority:

#include <iostream>
#include <queue>

int main() {
    // Declare a max-heap priority queue of integers
    std::priority_queue<int> pq;

    // Insert elements
    pq.push(10);
    pq.push(20);
    pq.push(5);

    // Display elements in order of priority
    std::cout << "Elements in priority order: ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";  // Access the highest-priority element
        pq.pop();  // Remove the highest-priority element
    }
    // Output: 20 10 5

    return 0;
}
