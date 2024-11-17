#include <bits/stdc++.h>

using namespace std;

vector<string> sorting(string s)
{
    string temp;
    vector<string> vec(10, " ");
    for (int i = 0; i <= s.size(); i++)
    {
        if (i < s.size() && s[i] != ' ')
        {
            temp = temp + s[i];
        }
        else
        {
            int pos = temp[temp.size() - 1] - '0';
            temp.pop_back();
            vec[pos - 1] = temp;
            temp.clear();
        }
    }
    return vec;
}


int main () {

    string s = "jangoo1 ghatiya3 ek2 hai5 company4";

    vector<string> output = sorting(s);
    for (int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }
    return 0;
     
} 
