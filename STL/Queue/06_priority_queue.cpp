/**
 * Using priority_queue as a Min-Heap
 * To change it to a min-heap (where the smallest element has 
 * the highest priority), we use a custom comparator. 
 * Here, we use std::greater<int> as the comparator.
 */

#include <iostream>
#include <queue>
#include <vector>

int main() {
    // Declare a min-heap priority queue using greater<int>
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // Insert elements
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);

    // Display elements in ascending order
    std::cout << "Elements in ascending priority: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    // Output: 5 10 20

    return 0;
}
