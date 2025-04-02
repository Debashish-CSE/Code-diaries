#include <iostream>
#include <deque>
using namespace std;

int main() {
    int T;
    cin >> T;

    deque<int> queue;

    for (int i = 0; i < T; i++) {
        int query;
        cin >> query;

        if (query == 1) {
            // Enqueue operation
            int n;
            cin >> n;
            queue.push_back(n);
        } else if (query == 2) {
            // Dequeue operation
            if (!queue.empty()) {
                queue.pop_front();
            }
        } else if (query == 3) {
            // Print the first element
            if (queue.empty()) {
                cout << "Empty!" << endl;
            } else {
                cout << queue.front() << endl;
            }
        }
    }

    return 0;
}
