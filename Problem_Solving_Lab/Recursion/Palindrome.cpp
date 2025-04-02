#include <iostream>
#include <vector>
using namespace std;

// Recursive function to check if the array is a palindrome
bool isPalindrome(const vector<int>& arr, int left, int right) {
    if (left >= right) {
        return true;  // Base case: All elements are checked, it's a palindrome
    }
    
    // If elements at left and right are not equal, it's not a palindrome
    if (arr[left] != arr[right]) {
        return false;
    }
    
    // Recur for the next pair of elements
    return isPalindrome(arr, left + 1, right - 1);
}

int main() {
    int N;
    cout << "Array size: ";
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Call the recursive function to check if the array is a palindrome
    if (isPalindrome(A, 0, N - 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}

