#include <bits/stdc++.h>

using namespace std;

void hello (){
    cout << "hi, how are you?" << endl;
}

void reply(){
    cout << "I am ok"<<endl;
}

void response(int a){
    
    if(a > 4){
        cout << "Today is good day";
    }
    else {
        cout << "lets meet tomorrow";
    }
}

void execution(void (*funct)()){
    funct();
}

void ask(void (*function)(int), int a){ // assign function to function pointer
    function(a);
}

int main (){

    void (*helloptr)();
    helloptr = &hello;
    
    execution(helloptr);

    helloptr = &reply;
    execution(helloptr);
    
    // Assign function pointers
    void (*responseptr)(int);

    responseptr = &response;
    ask(responseptr, 2); // lets meet tomorrow
    ask(responseptr, 7); // Today is good day


}