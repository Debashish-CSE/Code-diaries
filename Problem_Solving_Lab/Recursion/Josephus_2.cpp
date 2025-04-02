#include <iostream>
using namespace std;

int josephus(int n, int k) {
    int safePosition = 0;  // base case: when there's only one person, the safe position is 0 (zero-indexed)
    
    // Iteratively compute the safe position for every size of the circle from 2 to n
    for (int i = 2; i <= n; i++) {
        safePosition = (safePosition + k) % i;
    }
    
    return safePosition + 1;  // convert the result to 1-based indexing
}

int main() {
    int n, k;
    cin >> n >> k;
    
    cout << josephus(n, k) << endl;
    
    return 0;
}
