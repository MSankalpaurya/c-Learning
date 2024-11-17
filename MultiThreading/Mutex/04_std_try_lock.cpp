// std::try_lock();
/**
 * std::try_lock() tries to lock all the lokable objects passed in it one in given order
 * 
 * syntax  std::try_lock(mut1,mut2,mut3,mut4,...)
 * 1. on the success it return -1 (very important) otherwise return 0-based mutex index(if return 2 that means it not able to lock mut3) number which 
 *    it could not lock.
 * 2. if it fails to lock any of mutex then it will release all the mutex it locked before.
 * 3. if a call to try_lock results in an exception, unlock is called for any locked objects before
 *    rethrowing
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int X=0,Y=0;
mutex mtx1, mtx2;

void work(int seconds){
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}
void incrementxy(int &XorY, std::mutex &m, const char *desc ){
   for(int i=0; i<10; i++){
     m.lock();
     ++XorY;
     cout << desc << " " <<  XorY << " " << '\n';
     m.unlock();
     work(2);
    }
}

void consumerXY(){
    int usercount = 10;
    int xplusY = 0;
    while(true){
        int lockresult = std::try_lock(mtx1, mtx2);
        if(lockresult ==-1){
            if(X !=0 && Y!=0){
                --usercount;
                xplusY = xplusY+X+Y;
                X=0;
                Y=0;
                cout << " XplusY " << xplusY <<'\n';
            }
            mtx1.unlock();
            mtx2.unlock();
            if(usercount == 0)
            break;
        }
    }
}

int main (){
    thread t1 (incrementxy, ref(X), ref(mtx1), "X");
    thread t2 (incrementxy, ref(Y), ref(mtx2), "Y");
    thread t3 (consumerXY);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}