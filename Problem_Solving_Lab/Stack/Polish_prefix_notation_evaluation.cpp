#include <iostream>
#include <stack>
#include <cctype>
#include <sstream>
#include <algorithm>

using namespace std;

int applyOperator(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int evaluatePrefix(string expression) {
    stack<int> st;
    reverse(expression.begin(), expression.end());

    for (int i = 0; i < expression.length(); i++) {
        if (isspace(expression[i])) continue;

        if (isdigit(expression[i])) {
            int val = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                val = val * 10 + (expression[i] - '0');
                i++;
            }
            st.push(val);
            i--;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            int a = st.top(); 
            st.pop();
            int b = st.top();
            st.pop();
            int result = applyOperator(a, b, expression[i]);
            st.push(result);
        }
    }
    return st.top();
}

int main() {
    string prefixExpression = "+ 3 * 5 - 2 8";
    cout << "Prefix Evaluation: " << evaluatePrefix(prefixExpression) << endl;
    return 0;
}
