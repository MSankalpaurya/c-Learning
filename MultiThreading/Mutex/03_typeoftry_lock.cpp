#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx;

int value = 0;
void increment(){
    for(int i= 0; i< 10000; i++){
        if(mtx.try_lock()){
            ++value;
            mtx.unlock();
        }
    }
}

int main (){
    thread t1 (increment);
    thread t2 (increment);

    t1.join();
    t2.join();
    // here t1 and t2 are using common resouces;
    cout << "value = " << value << endl;
    return 0;
}