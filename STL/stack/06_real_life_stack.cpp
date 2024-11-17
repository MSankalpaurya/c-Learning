/**
 * 1. Balanced Parentheses/Brackets
 * Stacks can be used to check if parentheses, brackets, or braces in an expression are balanced. For example, in mathematical expressions or code, you might need to ensure every opening bracket has a matching closing bracket
 * Example: Balanced Parentheses Check
 */
#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& expr) {
    std::stack<char> s;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);  // Push opening brackets onto the stack
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;  // Stack empty means unbalanced
            
            char top = s.top();
            s.pop();  // Pop the top element
            
            // Check for matching pairs
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();  // If stack is empty, parentheses are balanced
}

int main() {
    std::string expr = "{[()]}";

    if (isBalanced(expr)) {
        std::cout << "Balanced\n";
    } else {
        std::cout << "Not Balanced\n";
    }

    return 0;
}
