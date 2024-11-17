#include <bits/stdc++.h>

using namespace std;

string converttolowercase(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            int pos = s[i] - 'A';
            s[i] = pos + 'a';
        }
    }
    return s;
}

string removenonalphanumeric(string &s)
{
    s = converttolowercase(s);
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
        {
            s[j] = s[i];
            j++;
        }
    }
    s.resize(j);
    return s;
}


bool isPalindrome(string s)
{
    s = removenonalphanumeric(s);
    if (s.empty() || s.size() == 1)
    {
        return true;
    }
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[(s.size() - 1) - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    string s = "asdfghjklkjhgfdsa";
    bool a = isPalindrome(s);

    if (a){
    cout << " it is palindrome";
    }
    else
    cout << " it is not palindrome";
    

    return 0;
}