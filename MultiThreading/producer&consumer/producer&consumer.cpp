#include <iostream>
#include <bits/stdc++.h>
#include <thread>
#include<mutex>
#include <condition_variable>

using namespace std;

std::mutex m1;
std::condition_variable cv;

vector <int> buffer;

const unsigned int buffersize= 50;

void producer(int val){
    while(val) {
        std::unique_lock<std::mutex> lock(m1);
        cv.wait(lock, []{return buffer.size() < buffersize;});
        buffer.push_back(val);
        cout << "produced : "<< val << endl;
        val--;
        lock.unlock();
        cv.notify_one();

    }
}

void consumer (){
    std::unique_lock<mutex> lock(m1);
    cv.wait(lock, [](){return buffer.size() > 0;});
    int val = buffer.back();
    buffer.pop_back();
    cout << "consumed : " << val << endl;
    lock.unlock();
    cv.notify_one();
}

int main (){

    std::thread t1 (producer, 100);
    std::thread t2 (consumer);

    t1.join();
    t2.join();


    return 0;
}

