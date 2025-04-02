#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

string removeDuplicateLetters(string s) {
    unordered_map<char, int> count;
    unordered_map<char, bool> inStack;
    stack<char> st;

    // Count the occurrences of each character
    for (char c : s) {
        count[c]++;
    }

    // Process each character in the string
    for (char c : s) {
        count[c]--; // Decrease the count of the current character

        // If the character is already in the stack, skip it
        if (inStack[c]) {
            continue;
        }

        // Maintain the lexicographical order in the stack
        while (!st.empty() && st.top() > c && count[st.top()] > 0) {
            inStack[st.top()] = false;
            st.pop();
        }

        // Push the current character to the stack
        st.push(c);
        inStack[c] = true;
    }

    // Build the result string from the stack
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
}

int main() {
    // Test cases
    string s1 = "bcabc";
    cout << removeDuplicateLetters(s1) << endl;  // Output: "abc"

    string s2 = "cbacdcbc";
    cout << removeDuplicateLetters(s2) << endl;  // Output: "acdb"

    return 0;
}
