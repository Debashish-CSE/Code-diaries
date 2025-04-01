#include <iostream>
#include <array>

using namespace std;

int main(){
    int count = 0;
    /*int arr[] = {1,2,3,4,5};
    for(auto i:arr){
        cout << i << " ";
        count++;
    }
    */
    array<int,5> arr{ 1, 2, 3, 4, 5 };
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
        count++;
    }
    cout << endl; 
    cout << "Length of the given array: " << count << endl;

}