#include <thread>
#include <iostream>
#include <mutex>
#include <vector>

std::mutex mtx;

void print()
{   
    for(int i = 0; i < 2; i++){
    mtx.lock();
    std::cout << "Hello  world "<<std::endl;
    mtx.unlock();
    }
}

int main()
{

    std::cout << "hardware_concurrency = " << std::thread::hardware_concurrency() << std::endl;
    int n = std::thread::hardware_concurrency();
    std::vector<std::thread> t(n);
    // int k = 0;
    // while (k < n)
    // {
    //     t[k] = std::thread(print);
    //     k++;
    // }
    for (int k = 0; k < n; k++){
        t[k] = std::thread(print);
    }
    for (int i = 0; i < n; i++)
    {
        t[i].join();
    }
}