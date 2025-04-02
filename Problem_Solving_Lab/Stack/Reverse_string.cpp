#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverse(string S) {
    stack<char> st;
    
    // Push all characters onto the stack
    for (char c : S) {
        st.push(c);
    }
    
    string reversed = "";
    
    // Pop characters from the stack and append to the result string
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }
    
    return reversed;
}

int main() {
    // Test the function
    string S1 = "GeeksforGeeks";
    cout << reverse(S1) << endl;  // Output: skeeGrofskeeG
    
    string S2 = "Geek";
    cout << reverse(S2) << endl;  // Output: keeG
    
    return 0;
}
