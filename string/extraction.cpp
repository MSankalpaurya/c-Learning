#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main (){

    string input = "asdfgBGHDUT8^$!~+-7301234&$%''jfg&*678";

    // vector <int> lower[26], upper[26], special[50], numeric[10];
    string lower   = "";
    string upper   = "";
    string numeric = "";
    string special = "";

    string lower1   = "";
    string upper1   = "";
    string numeric1 = "";
    string special1 = "";

    for (char c : input){
        if(islower(c)){
         lower = lower+ c;
        }
        else if (isupper(c)){
            upper = upper+c;
        }
        else if (isdigit(c)){
            numeric = numeric+c;
        }
        else {
           special = special+c; 
        }
    }
    cout << lower << endl;
    cout << upper << endl;
    cout << numeric << endl;
    cout << special << endl;

 /**
 * Extraction without using above function
 */

  for (int i =0; i < input.size(); i++){
      if (input[i] >= 'a' && input[i] <= 'z'){
        lower1 = lower1 + input[i];
      }
      else if (input[i] >= 'A' && input[i] <= 'Z'){
           upper1 = upper1 + input[i];
      }
      else if (input[i] >= '0' && input[i] <= '9'){
           numeric1 = numeric1 + input[i];
      }
      else {
        special1 =special1 + input [i];
      }
  }

    cout << lower1 << endl;
    cout << upper1 << endl;
    cout << numeric1 << endl;
    cout << special1 << endl;

}





