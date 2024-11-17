/**
 *  String allocate dynamic memory thats why it is godd in some cases for the char array
 * 
 *  when you get the input in string it will stop on the the space char
 * 
 *  to resolve this we have created the function get line
 * 
 * 
 * 
 * 
 * 
 */

#include <iostream>
#include <string>

using namespace std;

int main (){
    // char c[] = "hi how are you";
    //     int i = 0;
    //     while(c[i]!='\0'){
             
    //     cout << c[i];
    //     i++;
    //     }

    string s1,s2,s3,s4,s5,s6,s7;
    // // cin >> s2; // input "I AM SANKALP"
    // // cout << s2<<endl; // output "I"

    // getline (cin, s1); // it can take all the string as input and print whole string
    // cout << s1;

    s2 = "HI , ";
    s3 = "How are you?";
    s4 = " do I know you?";
    string s = s2+s3; // can directly add the string
    cout << s << endl;
    
    string news = s2.append(s4);
    cout << news << endl;
}