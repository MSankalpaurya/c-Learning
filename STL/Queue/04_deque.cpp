/**
 * TOPIC:Double-Ended Queue (Deque)
 * 
 *  A deque (pronounced "deck") is a special type of queue that allows 
 *  insertion and deletion of elements from both the front and the
 *  back. It combines the features of a stack (LIFO) and a queue
 *  (FIFO). Deques are more versatile than standard queues, and
 *  they are implemented as a part of the STL in C++.
 * 
 *  In C++, deque is used to implement both stack and queue
 *  operations because of its flexibility. Unlike a standard
 *  queue where elements are inserted at the back and removed
 *  from the front, a deque allows these operations at both ends.
 * 
 * Common operations on a deque:

    push_front(x): Insert x at the front.
    push_back(x): Insert x at the back (like queue.push(x)).
    pop_front(): Remove the element from the front (like queue.pop()).
    pop_back(): Remove the element from the back.
    front(): Access the element at the front.
    back(): Access the element at the back.

 */
#include <iostream>
#include <deque>  // Include deque header

int main() {

    /**
     * 
     * Deque is more versatile than a standard queue. It provides
     * more flexibility because you can add or remove elements
     * from both ends.
     * It provides O(1) time complexity for both
     * insertion and deletion at either end.
     * It’s implemented
     * internally using dynamic arrays or doubly linked lists.
     * 
     */
    std::deque<int> dq;

    // Insert elements at the front and back
    dq.push_back(10);  // {10}
    dq.push_front(20); // {20, 10}
    dq.push_back(30);  // {20, 10, 30}

    // Access the front and back elements
    std::cout << "Front element: " << dq.front() << std::endl;  // Output: 20
    std::cout << "Back element: " << dq.back() << std::endl;    // Output: 30

    // Remove front and back elements
    dq.pop_front();  // Removes 20, now {10, 30}
    dq.pop_back();   // Removes 30, now {10}

    std::cout << "Front element after pops: " << dq.front() << std::endl;  // Output: 10

    return 0;
}
