/**
 * 2. Reversing a String
 * Using a stack, we can reverse the characters of a string because of the LIFO property of the stack
 * Example: Reversing a String
 */
#include <iostream>
#include <stack>
#include <string>

std::string reverseString(const std::string& str) {
    std::stack<char> s;
    for (char ch : str) {
        s.push(ch);  // Push all characters onto the stack
    }

    std::string reversedStr;
    while (!s.empty()) {
        reversedStr += s.top();  // Append top of the stack to reversed string
        s.pop();  // Pop the character
    }
    return reversedStr;
}

int main() {
    std::string str = "Hello World!";
    std::string reversedStr = reverseString(str);

    std::cout << "Original String: " << str << std::endl;
    std::cout << "Reversed String: " << reversedStr << std::endl;

    return 0;
}
