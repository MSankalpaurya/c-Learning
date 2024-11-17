/**
 * TOPIC: Memory management in stack
 * Storage of Data Structures:
 *     Different data structures store data in different ways. 
 *     Here's a comparison relevant to queues:
 *  Array-Based Queue:
        Uses contiguous memory blocks, meaning all elements are stored in a single continuous area of memory.
        Efficient for accessing elements in sequence but less flexible in size management.
        Resizing involves allocating new memory and copying all existing elements.
 *  Linked List-Based Queue:
        Each element (node) has its own memory allocation, so memory is non-contiguous.
        More flexible in terms of resizing, as new elements are dynamically linked without requiring large chunks of continuous memory.
        Each node contains pointers, which means additional overhead in memory for managing links between nodes.

 *  Key Points to Remember:
        Queues in C++ STL handle memory automatically (internally using dynamic arrays or linked lists)
        Dynamic memory for queue elements is allocated on the heap, and you don't have to manually manage 
        memory for each element unless you're using custom implementations
        Understanding contiguous vs non-contiguous memory access is crucial for performance tuning, 
        especially when working with large datasets or in time-critical applications.
        
 */