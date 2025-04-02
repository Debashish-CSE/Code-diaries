#include <iostream>
#include <queue>
using namespace std;

// Function to reverse the queue recursively
void reverseQueue(queue<int>& q) {
    // Base case: If the queue is empty, return
    if (q.empty()) {
        return;
    }

    // Step 1: Remove the front element from the queue
    int frontElement = q.front();
    q.pop();

    // Step 2: Recursively reverse the remaining queue
    reverseQueue(q);

    // Step 3: After the recursive call, insert the front element to the back
    q.push(frontElement);
}

int main() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int N;
        cin >> N; // Number of elements in the queue
        
        queue<int> q;
        for (int i = 0; i < N; i++) {
            int element;
            cin >> element;
            q.push(element); // Enqueue elements
        }

        // Reverse the queue
        reverseQueue(q);

        // Print the reversed queue
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }

    return 0;
}
