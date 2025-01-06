#include <bits/stdc++.h>

using namespace std;

int reverse (int &a) {
    int r = 0;
    int b = 0;
    
    while (a > 0){

        if (a > 9) {
            r = a % 10;
            b = b * 10 + r;
            // cout << " valure of b :" << b;
            a = (a/10);
        }
        else {
            r = a;
            b = b * 10 + r;
            a = a /10;
        }
    }

    return b;


}

int main () {

    int a = 556021;

    int b = reverse(a);

    cout << "b = : " << b << endl; 

    return 0;
}