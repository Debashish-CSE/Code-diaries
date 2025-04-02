#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib> // For stoi (string to integer conversion)

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Pop two operands from the stack
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            // Perform the operation and push the result back to the stack
            if (token == "+") {
                st.push(a + b);
            } else if (token == "-") {
                st.push(a - b);
            } else if (token == "*") {
                st.push(a * b);
            } else if (token == "/") {
                // Division truncates toward zero in C++
                st.push(a / b);
            }
        } else {
            // Convert the token to an integer and push it to the stack
            st.push(stoi(token));
        }
    }

    // The final result will be the only element in the stack
    return st.top();
}

int main() {
    // Test cases
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << evalRPN(tokens1) << endl;  // Output: 9

    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << evalRPN(tokens2) << endl;  // Output: 6

    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(tokens3) << endl;  // Output: 22

    return 0;
}
