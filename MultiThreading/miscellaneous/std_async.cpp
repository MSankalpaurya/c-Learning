/**
 * TOPIC: std::async
 * 
 * NOTES:
 * 1. It runs a function asynchronously (potentially in a new thread) and
 *  returns a std::future that will hold the result.
 * 
 * 2. There are three launch policies for creating task:
 *    a) std::launch::async   (for to create Threading)
 *    b) std::launch::deffered (for to not creating Thread)
 *    c) std::launch::async | std::launch::deffered
 * 
 * How it work:
 * 1. It automatically creates a thread (or picks from internal thread pool) and
 *    a promise object for us
 * 2. Then passes the std::promise object to thread functions and returns the associated
 *    std::future object.
 * 3. when our passed argument functions exits then its value will be set in this promise 
 *    object, so eventually return value will be avilable in std::future objects
 * 
 * SIDE NOTES:
 * 1. We can send functor and lambda function as callback to std::async, it will work the same
 */

#include <iostream>
#include <thread>
#include <chrono>
#include<algorithm>
#include <future>

using namespace std;
using namespace std::chrono;
typedef long int  ull;


ull findodd(ull start, ull end){
    ull oddsum = 0;
    cout << "ThreadID : " << std::this_thread::get_id()<<endl;
    for (ull i = start; i<= end; i++){
        if(i & 1){
            oddsum +=i;
        }
       
    }
    return oddsum; // set the value for promise
}

int main (){

    ull start =0, end = 1900000000;

    // std::promise <ull > oddsum;  //creating the promise object
    // std::future<ull> oddfuture = oddsum.get_future(); // creating future object from promise object
    cout << "ThreadID : " << this_thread::get_id() << endl;

    cout << "thread created  if policy is std::launch::async!!" << endl;
    // std::future <ull> oddsum = std::async(std::launch::deferred, findodd, start, end); // thread creation or task creation
    std::future <ull> oddsum = std::async(std::launch::async, findodd, start, end); // thread creation or task creation
    // above first time thread will return something.

    // std::thread t1 (findodd, std::move(oddsum), start, end);

    cout << "waiting for result : "<< endl;
    cout << "oddsum : " << oddsum.get() << endl;
    cout << "completed" << endl;
    // t1.join();
    return 0;
}