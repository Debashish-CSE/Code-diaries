#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    
    // Iterate through the string
    for (char c : s) {
        // If it's an opening bracket, push it onto the stack
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } 
        // If it's a closing bracket, check for matching opening bracket
        else if (c == ')' || c == '}' || c == ']') {
            // If stack is empty or top of stack doesn't match, return false
            if (st.empty()) return false;
            
            char top = st.top();
            if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[')) {
                st.pop(); // Remove matching opening bracket
            }
            else{
                return false;
            }
        }
    }
    
    // If stack is empty, all brackets were matched; otherwise, return false
    return st.empty();
}

int main() {
    // Test cases
    string s1 = "()";
    cout << (isValid(s1) ? "true" : "false") << endl;  // Output: true

    string s2 = "()[]{}";
    cout << (isValid(s2) ? "true" : "false") << endl;  // Output: true

    string s3 = "(]";
    cout << (isValid(s3) ? "true" : "false") << endl;  // Output: false

    string s4 = "([])";
    cout << (isValid(s4) ? "true" : "false") << endl;  // Output: true

    return 0;
}