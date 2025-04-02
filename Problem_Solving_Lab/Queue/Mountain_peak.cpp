#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void findNextGreaterElements(const vector<int>& heights) {
    int n = heights.size();
    vector<int> result(n, -1);  // Initialize all results to -1
    stack<int> st;  // Stack to store indices of the heights array
    
    // Traverse from right to left
    for (int i = n - 1; i >= 0; --i) {
        // Remove all elements from the stack which are smaller or equal to the current element
        while (!st.empty() && heights[st.top()] <= heights[i]) {
            st.pop();
        }
        
        // If the stack is not empty, the top element is the next greater element
        if (!st.empty()) {
            result[i] = heights[st.top()];
        }
        
        // Push the current element's index onto the stack
        st.push(i);
    }
    
    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    
    findNextGreaterElements(heights);
    
    return 0;
}
//using queue

/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void findNextGreaterElements(const vector<int>& heights) {
    int n = heights.size();
    vector<int> result(n, -1);  // Initialize result with -1
    queue<int> q;  // Queue to store the indices of the heights

    // Traverse the list from right to left
    for (int i = n - 1; i >= 0; --i) {
        // Remove elements from the front of the queue which are smaller or equal to the current element
        while (!q.empty() && heights[q.front()] <= heights[i]) {
            q.pop();
        }

        // If there are elements left in the queue, the front element is the next greater element
        if (!q.empty()) {
            result[i] = heights[q.front()];
        }

        // Push the current element's index into the queue
        q.push(i);
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    findNextGreaterElements(heights);

    return 0;
}


*/