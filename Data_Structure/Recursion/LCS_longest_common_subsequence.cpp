#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to compute the LCS and return its length
int longestCommonSubsequence(string &s1, string &s2) {
    int m = s1.size();
    int n = s2.size();

    // Create a 2D DP array to store the length of LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // To get the actual LCS
    string lcs = "";
    int i = m, j = n;

    // Traceback from dp[m][n]
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs;  // Add this character to LCS
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Print the LCS
    cout << "Longest Common Subsequence: " << lcs << endl;

    return dp[m][n];
}

int main() {
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    int length = longestCommonSubsequence(s1, s2);

    cout << "Length of Longest Common Subsequence: " << length << endl;

    return 0;
}
