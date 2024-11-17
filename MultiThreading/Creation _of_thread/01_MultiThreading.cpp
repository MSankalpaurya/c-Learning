/**
 * Thread is also known as light weight process
 * 
 * WAYS TO CREATE THREAD IN C++
 * //1. Function Pointers
 * //2. Lambda Functions
 * //3. Functors
 * //4. Member Function
 * //5. Static Member Function
 * 
 */

//find the sum of all odd number from 1 to 1900000000 and all even number from 1 to 1900000000

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

typedef long long ull;

ull odd = 0;
ull even = 0;

void evensum(ull n)
{
    for (ull i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            even = even+i;
        }
    }
}

void oddsum(ull n)
{
    for (ull i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            odd = odd+i;
        }
    }
    // cout << odd << std::endl;
}

int main (){

    ull n = 190000000;

    auto startTime = high_resolution_clock::now();

    std::thread t1(evensum, n); // thread t1 is created
    std::thread t2(oddsum, n);  // thread t2 is created

    t1.join(); //  join the thread t1 to main thread
    t2.join(); //  join the thread t2 to main thread

    // evensum(n);
    // oddsum(n);

    auto endTime = high_resolution_clock::now();
    auto totalTime = duration_cast <milliseconds>(endTime - startTime);

    cout << "Total Time Taken = " << totalTime.count() << endl;

    cout << "Even Sum = " << even << std::endl;
    cout << "odd Sum = " << odd << std::endl;

    return 0;
}