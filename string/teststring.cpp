#include <iostream>
#include <string>

using namespace std;

int main (){


   char c[100000];
   cin.getline(c,100000);


    char * p;
    p = new char [100000];

    char *p_src = c;  
    char *p_dest = p;  

    
    while (*p_src != '\0') {
        *p_dest = *p_src; 
        p_src++;          
        p_dest++;         
    }
    *p_dest = '\0';  


    delete[] p;  
}