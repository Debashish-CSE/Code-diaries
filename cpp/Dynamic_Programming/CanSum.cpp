#include <iostream>

using namespace std;

bool canSum(int targetSum, int numbers[], int size){
    //base cases
    if(targetSum == 0) return true;
    if(targetSum < 0) return false;

    for(int i=0; i<size; i++){
        int remainder = targetSum - numbers[i];
        if(canSum(remainder, numbers, size) == true) return true;
    }

    return false;
}

int main(){
    int arr1[] = {5, 3, 4, 7};
    int arr2[] = {7, 14};

    cout << boolalpha; //to explicitly return true or false instead of 1 or 0
    cout << canSum(7, arr1, 4) << endl; // true
    cout << canSum(300, arr2, 2) << endl; // false

}