#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int item) {
    if (size <= 0) {
        return -1;
    }

    int beg = 0;
    int end = size - 1;
    int mid = beg + (end - beg) / 2;

    while (beg <= end && arr[mid] != item) {
        if (item < arr[mid]) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
        mid = beg + (end - beg) / 2;
    }

    return (beg <= end) ? mid : -1;
}

int main() {
    int data[] = {6,13,14,25,33,43,51,53,64,72,84,93,95,96,97};
    int size = sizeof(data) / sizeof(data[0]);
    int item = 33;

    int result = binarySearch(data, size, item);

    if (result != -1) {
        cout << "Item found at position " << result << endl;
    } else {
        cout << "Item is not in the list" << endl;
    }

    return 0;
}