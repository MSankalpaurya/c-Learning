#include <bits/stdc++.h>

using namespace std;


string reverse (string &a, int n){
    char temp = ' ';
    for (int i= 0; i < n/2; i++) {
         temp = a[(n-1) -i];
         a[(n-1)-i] = a[i];
         a[i] = temp;
        //  cout << a[i] << " "<<endl;
    }
    return a;

}

int main () {

    string a = "0002";
    int n = a.size();
    reverse(a.begin(), a.end());
    // string b = reverse (a, n);

    cout << "value of b : " << a;

    return 0;
}