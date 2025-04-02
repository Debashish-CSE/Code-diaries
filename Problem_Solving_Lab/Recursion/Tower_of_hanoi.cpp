#include <iostream>
using namespace std;

// Function to solve Tower of Hanoi recursively
void hanoi(int n, int source, int target, int auxiliary) {
    if (n == 1) {
        // Move disk from source to target
        cout << source << " " << target << endl;
    } 
    else {
        // Move n-1 disks from source to auxiliary
        hanoi(n - 1, source, auxiliary, target);
        
        // Move the nth disk from source to target
        cout << source << " " << target << endl;
        
        // Move n-1 disks from auxiliary to target
        hanoi(n - 1, auxiliary, target, source);
    }
}

int main() {
    int n;
    cin >> n;
    
    // The minimum number of moves is 2^n - 1
    int moves = (1 << n) - 1;  // This is 2^n - 1
    cout << moves << endl;
    
    // Call the function to print the moves
    hanoi(n, 1, 3, 2);
    
    return 0;
}
