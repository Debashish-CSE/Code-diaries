#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;  // If operand, add it to postfix expression
        }
        else if (c == '(') {
            s.push(c);  // If '(', push it to stack
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();  // Pop operators until '(' is found
                s.pop();
            }
            s.pop();  // Remove '('
        }
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();  // Pop operators based on precedence
                s.pop();
            }
            s.push(c);  // Push the current operator to stack
        }
    }
    while (!s.empty()) {
        postfix += s.top();  // Pop remaining operators from stack
        s.pop();
    }
    return postfix;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());  // Reverse the infix expression
    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    string postfix = infixToPostfix(infix);  // Convert to postfix (with reversed infix)
    reverse(postfix.begin(), postfix.end());  // Reverse the postfix to get prefix
    return postfix;
}

int main() {
    string infix;
    
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    cout << "Prefix expression: " << infixToPrefix(infix) << endl;

    return 0;
}
