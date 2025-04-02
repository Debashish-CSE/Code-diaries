#include <iostream>
#include <stack>
#include <cctype>
#include <unordered_map>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOperator(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int evaluateInfix(string expression) {
    stack<int> vals;
    stack<char> ops;

    for (int i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            int val = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                val = val * 10 + (expression[i] - '0');
                i++;
            }
            vals.push(val);
            i--;  // Adjust for the increment in the while loop
        }

        else if (expression[i] == '(') {
            ops.push(expression[i]);
        }

        else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = vals.top();
                vals.pop();
                int val1 = vals.top();
                vals.pop();
                char op = ops.top();
                ops.pop();
                vals.push(applyOperator(val1, val2, op));
            }
            ops.pop();  // Pop the '('
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                int val2 = vals.top();
                vals.pop();
                int val1 = vals.top();
                vals.pop();
                char op = ops.top();
                ops.pop();
                vals.push(applyOperator(val1, val2, op));
            }
            ops.push(expression[i]);
        }
    }

    while (!ops.empty()) {
        int val2 = vals.top();
        vals.pop();
        int val1 = vals.top();
        vals.pop();
        char op = ops.top();
        ops.pop();
        vals.push(applyOperator(val1, val2, op));
    }

    return vals.top();
}

int main() {
    string infixExpression = "3 + 5 * (2 - 8)";
    cout << "Infix Evaluation: " << evaluateInfix(infixExpression) << endl;
    return 0;
}
