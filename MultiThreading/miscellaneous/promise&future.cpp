/**
 * TOPIC: std::future and std::promise
 * 
 * NOTES:
 * 1.0 std::promise
 *         a) used to set value or exception.
 * 
 * 2.0 std::future
 *         a) used to get value from promise
 *         b) ask promise if the value is avilable
 *         c) wait for the promise
 */

#include <iostream>
#include <thread>
#include <chrono>
#include<algorithm>
#include <future>

using namespace std;
using namespace std::chrono;
typedef long int  ull;


void findodd(std::promise<ull> &&oddsumpromise , ull start, ull end){
    ull oddsum = 0;
    for (ull i = start; i<= end; i++){
        if(i & 1){
            oddsum +=i;
        }
       
    }
    oddsumpromise.set_value(oddsum); // set the value for promise
}

int main (){

    ull start =0, end = 1900000000;

    std::promise <ull > oddsum;  //creating the promise object
    std::future<ull> oddfuture = oddsum.get_future(); // creating future object from promise object

    cout << "thread created " << endl;
    std::thread t1 (findodd, std::move(oddsum), start, end);
//                             ||
//                             \/
//  A thread t1 is started to run the findodd function, passing the promise using std::move() to ensure the ownership is transferred to the thread.

    cout << "waiting for result : "<< endl;
    cout << "oddsum : " << oddfuture.get() << endl;
    cout << "completed" << endl;
    t1.join();
    return 0;
}
