#include <bits/stdc++.h>

using namespace std;

bool ispresent(string &s1, string &s2) {
    if (s2.size() > s1.size()) return false;
    int n = s1.size()-s2.size();
    for (int i = 0; i <= n; i++) {
        bool found = true;
        for (int j = 0; j < s2.size(); j++) {
            if (s1[i + j] != s2[j]) {
                found = false;
                break;
            }
        }
        if (found) return true;
    }
    return false; 
}

int main() {
    while(1)
    {
    string s1, s2;
    cout << "Enter first string: " << endl;
    cin >> s1;
    cout << "Enter second string: " << endl;
    cin >> s2;
    
    bool a = ispresent(s1, s2);
    cout << a << endl;
    }
    
    return 0;
}
