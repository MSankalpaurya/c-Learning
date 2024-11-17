// question is you have to create thread t1,t2,t3,t4.....so on based on thread_count
// you have given string "abcdefg"
// thread t1 will print "abcd", t2 (efga), t3 (bcde), t4 (fgab) ...and so on based on char_count
// you have the given the thread_count

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

std::mutex mtx;             // Mutex to control output sequence
std::condition_variable cv; // Condition variable for thread synchronization
int current_thread = 0;     // Tracks which thread should print

void printSubstring(const std::string &str, int start, int char_count, int thread_id, int thread_count)
{
    int str_len = str.length();
    std::string result = "";

    // Create substring based on circular index
    for (int i = 0; i < char_count; ++i)
    {
        result += str[(start + i) % str_len];
    }

    // Synchronize output using condition variable and mutex
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [&]
            { return thread_id == current_thread; });

    // Print the result for the current thread
    std::cout << "Thread " << thread_id + 1 << " :  " << result << std::endl;

    // Move to the next thread
    current_thread = (current_thread + 1) % thread_count;
    cv.notify_all();
}

int main()
{
    std::string str = "abcdefg";
    int thread_count = 10;
    int char_count = 7;

    std::vector<std::thread> threads(thread_count);

    // Create and launch threads
    for (int k = 0; k < thread_count; k++)
    {
        int start = (k * char_count) % str.length();
        // Start each thread at different positions
        threads[k] = std::thread(printSubstring, str, start, char_count, k, thread_count);
    }

    // Join the threads
    for (int i = 0; i < thread_count; i++)
    {
        threads[i].join();
    }

    return 0;
}
