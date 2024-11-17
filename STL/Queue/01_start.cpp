/**
 * TPOIC: queue
 * 
 * A queue is a linear data structure that follows the FIFO (First In, First Out) principle. 
 * This means that elements are inserted from the rear and removed from the front. 
 * It's like waiting in line: 
 * the first person in line is served first.
 * 
 * 
 * Basic Operations on a Queue:
 *    1. Enqueue: Add an element to the back of the queue
 *    2. Dequeue: Remove an element from the front of the queue
 *    3. Front: Retrieve the element at the front of the queue
 *    4. Back: Retrieve the element at the back of the queue
 *    5. Empty: Check if the queue is empty
 *    6. Size: Get the number of elements in the queue.
 * 
 * Queue Syntax in C++
 *   You can use the queue container from the <queue> header.
 *   Here’s an example to demonstrate the basic operations of a 
 *   queue.
 * 
 * NOTE:
 * Key Points:
 *   1. The queue is not a random-access data structure. 
 *   You can only interact with the element at the front and the 
 *   element at the back
 *   2. The FIFO order ensures that elements are processed in the order 
 *   they were added.
 */

#include <iostream>
#include <queue>  // Include the queue header

int main() {
    std::queue<int> q;  // Create a queue of integers

    // Enqueue elements
    q.push(10);  // Adds 10 to the queue
    q.push(20);  // Adds 20 to the queue
    q.push(30);  // Adds 30 to the queue

    // Get the front element
    std::cout << "Front element: " << q.front() << std::endl;  // Output: 10

    // Get the back element
    std::cout << "Back element: " << q.back() << std::endl;  // Output: 30

    // Dequeue an element
    q.pop();  // Removes the front element (10)

    // Front element after one dequeue
    std::cout << "Front element after pop: " << q.front() << std::endl;  // Output: 20

    // Check the size of the queue
    std::cout << "Size of queue: " << q.size() << std::endl;  // Output: 2

    // Check if the queue is empty
    if (q.empty()) {
        std::cout << "Queue is empty" << std::endl;
    } else {
        std::cout << "Queue is not empty" << std::endl;
    }

/*

  Explanation:

    q.push(x): Adds an element x to the back of the queue.
    q.pop(): Removes the front element from the queue.
    q.front(): Returns the element at the front of the queue.
    q.back(): Returns the element at the back of the queue.
    q.empty(): Returns true if the queue is empty, otherwise returns false.
    q.size(): Returns the number of elements in the queue.

    //Output

    Front element: 10
    Back element: 30
    Front element after pop: 20
    Size of queue: 2
    Queue is not empty



*/

    return 0;
}
