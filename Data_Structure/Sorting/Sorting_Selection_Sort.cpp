#include <bits/stdc++.h>

using namespace std;


/* Sort array using Selection Sort */
void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {

        // Assume the current position holds the minimum element
        int min_idx = i;

        // Iterate through the unsorted remaining array to find the actual minimum
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {                              
                min_idx = j; // Update min_idx if a smaller element is found 
            }
        }
        // Move minimum element to its correct position
        swap(arr[i], arr[min_idx]);
    }
}


void printArray(vector<int> &arr) {
    for (int &i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 47, 15, 28, 11};
    cout << "Original array: ";
    printArray(arr); 

    selectionSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}

/* Time complexity = O(n^2) */