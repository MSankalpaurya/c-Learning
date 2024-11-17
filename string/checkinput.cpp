#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s;
    bool k = false;
    while (k == false)
    {
        cout << "Enter the input= " << endl;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (!(s[i] >= '0' && s[i] <= '9')) {
                k = false;
                cout << " input is not a number " << endl;
                break;
            }
            else
            {
                k = true;
            }
        }
        
    }
    // if (k)
    // {
        int num = stoi(s);

        if (num % 2 == 0)
        {
            cout << "even number";
        }
        else
        {
            cout << "odd number";
        }
    // }

    return 0;
}