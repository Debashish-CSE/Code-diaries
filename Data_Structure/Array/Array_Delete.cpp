#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int n=6, k=4, la[n]; 
    /* 
        k = index where item will be deleted(suppose array starts from index 1)
        n = number of elements
        la[n] = linear array name
    */

    cout<< "Array: ";
    for(int i=0; i<n; i++){
        la[i] = rand() % 100; //creating random elements between 0 and 100 for la[n]
        cout << la[i] << " ";
    }
    cout << endl;
    
    //deleting from linear array
    int item = la[k-1]; //kth index which will be deleted

    for(int j=k-1; j<=n-1; j++){
        la[j] = la[j+1]; //move array upwards
    }
    n = n-1; //resize the array

    cout << "Array after deleting at 4th index: ";
    for(int i=0; i<n; i++){
        cout << la[i] << " ";
    }
    cout << endl;
}

