/**
 * DETACH NOTES
 * 1. Once a thread is started we wait for this thread to finish by calling jion()
 *    function on thread object
 * 2. Always check before detaching a thread that it is jionable otherwise we may end
 *    up double detaching and double detach() will result into programm termination
 * 3. If we have detach thread and main function is returning then the detach thread
 *    execution is suspended
 */

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void run (int x) {
    while (x-- > 0)
    cout << "hi am function" << endl;
    std::this_thread::sleep_for(chrono::seconds(5));
}

int main () {
    std::thread t (run, 10);
    cout << "Main"<< endl;
    t.detach();
    // t.detach(); // throw the segmentation fault 
    //instead use
    if(t.joinable()){
        t.detach();
    }
    cout << "main after" << endl;
    /**
     * ~/sankalp/MultiThreading/Join_and_detach$ ./a.out 
     *   Main
     *   main after
     *   hi am function
     *   hi am function
     *   jangoo@jangoo-Lenovo-V15-G2-ITL-Ua:~/sankalp/MultiThreading/Join_and_detach$ ./a.out 
     *   Main
     *   main after
     *   jangoo@jangoo-Lenovo-V15-G2-ITL-Ua:~/sankalp/MultiThreading/Join_and_detach$ ./a.out 
     *   Main
     *   main after
     *   hi am function
     *   hi am function
     *   hi am function
     *   hi am function
     *   hi am function
     *   hi am function
     *   jangoo@jangoo-Lenovo-V15-G2-ITL-Ua:~/sankalp/MultiThreading/Join_and_detach$
     */
    /**
     * why diffrent output is coming ? 
     * first request goes to OS(Operating System) and that it take some time to create function in the thread
     * and come back and print "Main" and "main after"; but os taking more time to create the 
     * thread function then main thread.
     * 
     * detach thread means you are telling to wait for thread to complete;
     */
    return 0;
}