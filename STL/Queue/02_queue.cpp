/**
 * TOPIC: Memory storage in Queue
 *     The queue container in C++ uses dynamic memory allocation internally. 
 *     It can grow and shrink as you push and pop elements. 
 *     It manages its own memory on the heap, 
 *     so you don’t have to worry about the size of the queue or
 *     memory leaks, as long as you use the standard std::queue 
 *     and don’t forget to pop elements when necessary.
 * 
 * How a Queue Uses Memory:
 *  1. The queue is typically implemented using a dynamic array 
    *  or linked list. Each element added to the queue is dynamically 
    *  allocated on the heap. As elements are pushed, more memory is 
    *  allocated if necessary. When an element is popped, the memory 
 *  for that element is deallocated:
 *  2. Memory growth: If the internal storage of a queue 
 *     (like a dynamic array) runs out of space, it allocates a 
 *     larger chunk of memory, copies the elements, and frees 
 *     the old memory.
 * 
 * 
 */

#include <iostream>
#include <queue>

using namespace std;

int main (){

    std::queue<int> q;  // Creates a queue using heap memory
    q.push(10);         // Push allocates space for 10 on the heap
    q.push(20);         // Another allocation happens for 20
    q.pop();            // Front element (10) is deallocated


    return 0;
}