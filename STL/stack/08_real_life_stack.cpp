/**
 * 3. Expression Evaluation (Postfix/Prefix)
 * Stacks can be used to evaluate mathematical expressions, especially postfix (Reverse Polish Notation) or prefix expressions
 * Example: Postfix Expression Evaluation
 * A postfix expression is an expression where the operator comes after the operands, e.g., 2 3 + means 2 + 3
 * 
 * other exmple is 4. Undo Mechanism in Editors
 */
#include <iostream>
#include <stack>
#include <string>

int evaluatePostfix(const std::string& expr) {
    std::stack<int> s;

    for (char ch : expr) {
        // If the character is a digit, push it onto the stack
        if (isdigit(ch)) {
            s.push(ch - '0');  // Convert char to int
        } else {
            // Operator encountered, pop two elements from the stack
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            // Perform the operation and push the result back onto the stack
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();  // The result is on top of the stack
}

int main() {
    std::string expr = "53+82-*";
    std::cout << "Postfix Evaluation: " << evaluatePostfix(expr) << std::endl;

    return 0;
}
