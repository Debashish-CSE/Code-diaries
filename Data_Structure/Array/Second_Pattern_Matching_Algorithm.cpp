#include <iostream>
#include <vector>
#include <string>
// Second pattern matching algorithm
using namespace std;

// Helper function to build the LPS (Longest Prefix Suffix) table
vector<int> computeLPS(const vector<char>& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0); // LPS table
    int len = 0;          // Length of the previous longest prefix suffix
    int i = 1;            // Index for traversing pattern

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Second pattern matching function
void secondPatternMatching(const vector<char>& text, const vector<char>& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = computeLPS(pattern);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index: " << i - j << endl;
            j = lps[j - 1]; // Continue to find more matches
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

// Helper function to convert input string to a vector of characters
vector<char> readInput() {
    string input;
    cin >> input;
    return vector<char>(input.begin(), input.end());
}

int main() {
    // Reading text and pattern as input
    cout << "Enter text: ";
    vector<char> text = readInput();

    cout << "Enter pattern: ";
    vector<char> pattern = readInput();

    secondPatternMatching(text, pattern);

    return 0;
}










