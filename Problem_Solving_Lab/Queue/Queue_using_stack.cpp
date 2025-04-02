#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> stack1, stack2;

public:
    // Constructor to initialize the two stacks
    MyQueue() {}

    // Push element x to the back of the queue
    void push(int x) {
        stack1.push(x);
    }

    // Removes the element from the front of the queue and returns it
    int pop() {
        // If stack2 is empty, move all elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }

    // Get the front element of the queue
    int peek() {
        // If stack2 is empty, move all elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    // Returns whether the queue is empty
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    MyQueue myQueue;

    // Push elements into the queue
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2]

    // Peek the front of the queue
    cout << myQueue.peek() << endl;  // Output: 1

    // Pop the front element of the queue
    cout << myQueue.pop() << endl;  // Output: 1

    // Check if the queue is empty
    cout << myQueue.empty() << endl;  // Output: false

    // Pop the front element again
    cout << myQueue.pop() << endl;  // Output: 2

    // Check if the queue is empty again
    cout << myQueue.empty() << endl;  // Output: true

    return 0;
}
