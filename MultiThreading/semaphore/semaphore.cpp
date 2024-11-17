/**
 *Semaphore: It is like signally object for the thread
 * 
 * Global binary semaphore instances
 * Object counts are set to zero
 * objects are in non-signaled states
 * 
 * 
 * compile:
 * g++ -std=c++20 -pthread semaphore.cpp -o semaphore_program
 */

#include <iostream>
#include <semaphore>
#include <thread>
#include <chrono>

/**
 * Here, two semaphores are created:
 * smphSignalMainToThread: This semaphore is initialized to 0, meaning the secondary thread will wait for a signal from the main thread.
 * smphSignalThreadToMain: This semaphore is also initialized to 0, meaning the main thread will wait for a signal from the secondary thread.
 */

std::binary_semaphore smphSignalMainToThread{0};
std::binary_semaphore smphSignalThreadToMain{0};

/*
This function runs in the secondary thread.
smphSignalMainToThread.acquire();: This makes the thread wait until it receives a signal from the main thread (when the semaphore is posted).
Once the signal is received, it prints "Thread got the signal".
std::this_thread::sleep_for(std::chrono::seconds(3));: This makes the thread pause for 3 seconds to simulate some processing time.
After the pause, it prints "Thread sends the signal" and then uses smphSignalThreadToMain.release(); to signal the main thread that it has finished its work.
*/

void ThreadProc() {
    // Wait for signal from main proc by attempting to decrement the semaphore
    smphSignalMainToThread.acquire();

    std::cout << "Thread got the signal" << std::endl;

    // Simulate processing
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "Thread sends the signal" << std::endl;
    // Signal to main thread
    smphSignalThreadToMain.release();
}


/*
std::thread t1(ThreadProc);: This line creates a new thread that runs the ThreadProc function.
It then prints "Main sends the signal".
smphSignalMainToThread.release();: This sends a signal to the secondary thread, allowing it to continue.
smphSignalThreadToMain.acquire();: The main thread waits for a signal from the secondary thread, meaning it will pause until the secondary thread indicates it’s done.
Finally, t1.join(); ensures that the main thread waits for the secondary thread to finish before it exits.
*/
int main() {
    std::thread t1(ThreadProc);

    std::cout << "Main sends the signal" << std::endl;

    // Release signal to thread
    smphSignalMainToThread.release();

    // Wait for signal from thread
    smphSignalThreadToMain.acquire();

    // Join the thread
    t1.join();

    return 0;
}
