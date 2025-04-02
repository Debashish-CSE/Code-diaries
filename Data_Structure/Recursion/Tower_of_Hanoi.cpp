#include <iostream>
using namespace std;

// Tower of Hanoi puzzle
int towerOfHanoi(int n, char source, char destination, char auxiliary) {
    // Base case: when there is only one disk, move it from source to destination
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return 1;  // Only one move is required
    }
    
    // Recursive case: Move n-1 disks from source to auxiliary peg using destination as auxiliary
    int moves1 = towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    int moves2 = 1;  // This is the move for the nth disk
    
    // Move the n-1 disks from auxiliary to destination using source as auxiliary
    int moves3 = towerOfHanoi(n - 1, auxiliary, destination, source);
    
    // Total moves is the sum of the above three parts
    return moves1 + moves2 + moves3;
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    // Calculate and display the total minimum moves required using recursion
    cout << "The moves are as follows:" << endl;
    int totalMoves = towerOfHanoi(n, 'A', 'C', 'B');  // 'A' is the source, 'C' is the destination, 'B' is auxiliary
    
    // Output the total minimum number of moves
    cout << "Minimum number of moves required: " << totalMoves << endl;

    return 0;
}

/* Minimum number of moves = 2^n-1 */