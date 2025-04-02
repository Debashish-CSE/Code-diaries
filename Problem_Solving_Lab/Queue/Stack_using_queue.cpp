#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> queue1, queue2;

public:
    // Push element x onto stack
    void push(int x) {
        // Push the element to queue1
        queue1.push(x);
    }

    // Removes the element on the top of the stack and returns it
    int pop() {
        // Move all elements except the last one from queue1 to queue2
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }

        // The last element in queue1 is the top element of the stack
        int topElement = queue1.front();
        queue1.pop();  // Remove it from queue1

        // Swap queue1 and queue2 to reuse them for the next operations
        swap(queue1, queue2);

        return topElement;
    }

    // Get the top element
    int top() {
        // Move all elements except the last one from queue1 to queue2
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }

        // The last element in queue1 is the top element of the stack
        int topElement = queue1.front();

        // Move the element to queue2 again (to maintain the queues for future operations)
        queue2.push(topElement);
        queue1.pop();

        // Swap queue1 and queue2 to reuse them for the next operations
        swap(queue1, queue2);

        return topElement;
    }

    // Returns whether the stack is empty
    bool empty() {
        return queue1.empty();
    }
};

int main() {
    MyStack myStack;

    // Test the stack operations
    myStack.push(1);  // stack: [1]
    myStack.push(2);  // stack: [1, 2]
    cout << myStack.top() << endl;   // Output: 2
    cout << myStack.pop() << endl;   // Output: 2
    cout << myStack.empty() << endl; // Output: false
    cout << myStack.pop() << endl;   // Output: 1
    cout << myStack.empty() << endl; // Output: true

    return 0;
}
