#include<bits/stdc++.h>

using namespace std;

string reverse(string s, int start, int end){
    while(start < end){
      char temp = s[start];
      s[start] = s[end];
      s[end] = temp;
      start++;
      end--;
    }
    return s;
}


void reverseWords(string &s, int size){
    int start =0;
    for (int i = 0; i <= size; i++){
    if (s[i]== ' ' || s[i] == '\0' || s[i] == ','){
        s = reverse(s, start, i-1);
        start = i+1;
    }
  }
}
int main (){
    string s = "Hi ,how are you";
    // string s = "sankalp maurya";
    int end = s.size()-1;
    string output = reverse(s,0,end); 
    cout << output << endl;
    reverseWords(output, end+1);
    cout << output;
    return 0;
}
