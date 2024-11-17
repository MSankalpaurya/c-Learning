/**
 * TOPIC:CONDITIONAL VARIABLE (CV)
 * 
 * IMPORTANT POINTS:
 * A) NOTIFY OTHER THREAD
 * B) WAITING FOR SOME CONDITIONS
 * 
 * 1. Condition variable allows running threads to wait on some conditions and once those 
 *    condition are met the waiting thread is nofied using 
 *    a) notify_one();
 *    b) notify_all();
 * 
 * 2. You need mutex to use condition variable
 * 3. If some thread want to waitt on some condition then it has to do these things
 *    a) acquire the mutex lock using std::unique_lock <std::mutex> lock(m);
 *    b) execute wait, wait_for, or wait_until. thw wait operations automatically
 *       release the mutex and suspend the excution of the thread.
 *    c) when the condition variable is notified , the thread is awakened, and the 
 *       mutex is atomically reacquired. The thread should then check the condition and resume waiting 
 *       if the wake up was spurious
 * 
 * NOTE:
 * 1. Condition variable used to synchronized two or more thread
 * 2. Best use case of condition variable is Produceer/Consumer problem
 * 
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

using namespace std;

std::condition_variable cv;
std::mutex mtx;

long balance = 0;

void addmoney(int money)
{
    std::lock_guard <mutex> lock(mtx);
    balance = balance + money;
    cout << "Amount added to customer account = " << balance << endl;
    cv.notify_one();
}

void withdrawMoney(int money)
{
    std::unique_lock<mutex> log(mtx);
    //------------------------NEED TO STUDY IN DEEP------------------------------
    // cv.wait(log, [&]() { // lambda expression
    //     if (balance != 0)
    //     {
    //         return true;
    //     }
    //     return false;
    // });
    //here you can write like this
    while(!balance){
        cv.wait(log);
    }
    if (balance >= money)
    {
        balance = balance - money;
        cout << "Amount deducted :" << money << endl;
    }
    else
    {
        cout << "Amount can not be deducted, current balance is less than " << money << endl;
    }
    cout << "current balance is " << balance << endl;
}


int main (){
    thread t1 (withdrawMoney , 600);
    // std::this_thread::sleep_for(std::chrono::seconds(5));
    thread t2 (addmoney , 500);
    t1.join();
    t2.join();
    return 0;
}