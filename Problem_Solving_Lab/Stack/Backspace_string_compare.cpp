#include <iostream>
#include <string>
using namespace std;

string processString(const string& str) {
    string result;
    for (char c : str) {
        if (c == '#') {
            if (!result.empty()) {
                result.pop_back(); // Simulate backspace by removing the last character
            }
        } else {
            result.push_back(c); // Add character to result
        }
    }
    return result;
}

bool backspaceCompare(string s, string t) {
    return processString(s) == processString(t); // Compare the processed strings
}

int main() {
    // Test cases
    string s1 = "ab#c";
    string t1 = "ad#c";
    cout << (backspaceCompare(s1, t1) ? "true" : "false") << endl;

    string s2 = "ab##";
    string t2 = "c#d#";
    cout << (backspaceCompare(s2, t2) ? "true" : "false") << endl;

    string s3 = "a#c";
    string t3 = "b";
    cout << (backspaceCompare(s3, t3) ? "true" : "false") << endl;

    return 0;
}
