#include <iostream>
#include <vector>

using namespace std;

void swapofinput(int a, int b)
{

    int &x = a;
    int &y = b;
    int c = x;

    a = y;
    b = c;
    cout << "b\n"
         << a;
    cout << "a\n"
         << b;
}

void appendVector(std::vector<int>&vec, int x){
    vec.push_back(x);
    for(int i=0; i< vec.size(); i++){
    cout << "Vector : ["<<i<<"]" << vec[i] << endl;
}
}
void constVector(const std::vector<int>&vec){
    for(int i=0; i< vec.size(); i++){
    cout << "Vector : ["<<i<<"]" << vec[i] << endl;
}
}

// Need to study pointer

// void updateValue(int *ptr) {
//     *ptr = 100;
// }

void swap(int &a, int &b)
{
    a = a+b;
    b = a-b;
    a = a-b;
}

void referencebyfunction(int &x){

    x++;
    cout << "referencebyfunction" << x << endl;
}

int returnreference(int &x, int &y){
    x = x+y;
    return x;
}

int main()
{
    int a = 100;
    int b = -5;
    std::vector <int> vec = {1,2,3}; 
    swap(a,b);
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    swapofinput(a,b);
    referencebyfunction(a);
    constVector(vec);
    cout << "for the constant value"<< std::endl;
    appendVector(vec, 4);
    
    

    return 0;
}