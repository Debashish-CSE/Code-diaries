#include <bits/stdc++.h>

using namespace std;

// function to get maximum value in arr[]
int getMax(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[], according to the digit represented by exp.
void countSort(int arr[], int n, int exp){

    // Output array
    int output[n];
    // Finding the maximum element of array inputArray[].
    int M = 0;
    for (int i = 0; i < n; i++){
        M = max(M, arr[i]);
    }
    // Initializing countArray[] with 0
    vector<int> countArray(M + 1, 0);

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        countArray[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        countArray[i] += countArray[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[countArray[(arr[i] / exp) % 10] - 1] = arr[i];
        countArray[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[],
    // so that arr[] now contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}


// function to sort arr[] of size n using Radix Sort
void radixsort(int arr[], int n){

    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit.
    // Instead of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}


int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 750, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);

    radixsort(arr, n);
    print(arr, n);
    return 0;
}
 /* Time complexity of O(d * (n + b)) 
  where d = number of digits, n = number of elements, and b = base of the number system */
