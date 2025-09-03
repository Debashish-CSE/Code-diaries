#include <bits/stdc++.h>
using namespace std;

vector<int> next_higher_peak(vector<int> &heights)
{
    int n = heights.size();    // Get the number of peaks
    vector<int> result(n, -1); // Initialize result vector with -1
    stack<int> st;             // Stack to keep track of indices

    for (int i = 0; i < n; ++i)
    {
        // While the stack is not empty and the current peak is higher than the peak at the index stored at the top of the stack
        while (!st.empty() && heights[i] > heights[st.top()])
        {
            int idx = st.top();       // Get the index from the top of the stack
            st.pop();                 // Remove the index from the stack
            result[idx] = heights[i]; // Update the result for that index with the current peak
        }
        st.push(i); // Push the current index onto the stack
    }

    return result; // Return the result vector
}

int main()
{
    int n;

    cin >> n; // Read the number of peaks from the user

    vector<int> heights(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i]; // Read each peak height from the user
    }

    vector<int> result = next_higher_peak(heights); // Call the function to get the result

    // Print result

    for (int height : result)
    {
        cout << height << " "; // Output each element in the result vector
    }
    cout << endl;

    return 0;
}
