/** 
 * JOIN NOTES
 * 1. Once the thread is started we wait for this thread to finish by calling join()
 *    function on thread
 * 2. Always check before detaching a thread that it is Joinable otherwise we may
 *    end up double detaching and doyble detach() will result into programm termination
 * 3. If we naver detach thread and main function is returning then the detach thread 
 *    execution is suspended
 * 
 * NOTES
 * Either join() or detach() should be called on thread object; otherwise during thread 
 * object's destructor will terminate the programm. Beacuse inside the destructor it checks if 
 * thread is still joinable ? if yes then it terminates the program
*/
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void run (int x) {
    while (x-- > 0)
    cout << "hi am function" << endl;
    std::this_thread::sleep_for(chrono::seconds(2));
}

int main () {
    std::thread t (run, 10);
    cout << "main before" << endl;
    t.join(); // here the thread waited to finish // and wait for the 3 second for the print of "main after"
    // here you wrote lot of code and you do not that you join the thrad or not

    // the should tou need to check id the join before or not
    if(t.joinable()){
        t.join();
    }

    // t.join(); // double join resultant in crash
    /**
     * ./a.out 
    main before
    hi am function
    hi am function
    hi am function
    hi am function
    hi am function
    hi am function
    hi am function
    hi am function
    hi am function
    hi am function
    terminate called after throwing an instance of 'std::system_error'
    what():  Invalid argument
    Aborted (core dumped)
     */
    cout << "main after" << endl;
    return 0;
}
