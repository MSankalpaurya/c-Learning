/**
 * SLEEP IS:
 * I am done with my timeslice, and plese don't give me another one for at least 'n' millisecond.
 * the OS doesn't even try to schedule the sleeping thread until requested time has passed
 * 
 * POINTS:
 * 1. It will keep the lock and sleep
 * 2. Sleep is directly to thread, it is theread function
 * 
 * 
 * WAIT IS:
 * I am done with my timeslice. Don't give me another timeslice until someone calls notify()
 * notifyAll();
 * 
 * As with sleep(), the OS won't even try to schedule your task unless someone call notify()
 * (or one of a few other wakeup scenarios occurs).
 * 
 * POINTS:
 * 1. It releases the lock and wait.
 * 2. Wait is on condition variable, it is like there is a condition variable in a thread and wait is applied to that cv
 *    but it ends up putting thread in waiting state
 * 
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
using namespace std::chrono;


