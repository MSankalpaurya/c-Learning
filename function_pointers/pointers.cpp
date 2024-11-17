#include <iostream>

using namespace std;

void greet() {
    cout << "Hello, World!" << endl;
}

void farewell() {
    cout << "Goodbye, World!" << endl;
}

int youknowme(bool a){
    cout << "You KNOW Me";
    return 1;
}

void executeFunction(void (*func)()) {
    func();
}

int testingyouknowme( int (*function)(bool a), bool a) {
    return function(a);                                     // write function signature and pass the arguments
}

int main() {

    void (*functionPtr)();

    functionPtr = &greet;
    
    executeFunction(functionPtr);  // output will be    Hello, World! 

    functionPtr = &farewell;

    executeFunction(functionPtr);   // output will be Goodbye, World!

    int (*youknowmeptr)(bool a); // create the 
    
    youknowmeptr = &youknowme;
    testingyouknowme(youknowmeptr, true);


    return 0;
}
