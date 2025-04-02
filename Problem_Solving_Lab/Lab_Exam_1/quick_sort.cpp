#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int a, int b){
    int temp=0;
    temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int p_index = start;
    for(int i=start; i<=(end-1); i++){
        if(arr[i] <= pivot){
            swap(arr[i], arr[p_index]);
            p_index = p_index+1;
        }
    }
    swap(arr[p_index], arr[end]);
    return p_index;
}

void Quicksort(int arr[], int start, int end){
    if(start < end){
        int p_index = partition(arr, start, end);
        Quicksort(arr, start, p_index-1);
        Quicksort(arr, p_index+1, end);
    }
}



int main(){
    int arr[] = {2,4,1,6,3,8,5,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr[0], arr[n-1]);
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;

    Quicksort(arr, 0, n-1);
    for(auto i:arr){
        cout << i << " ";
    }
    cout << endl;

}