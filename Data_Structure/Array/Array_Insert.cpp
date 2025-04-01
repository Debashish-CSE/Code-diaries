#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int n=6, k=4, item=27, la[n]; 
    /* 
        k = index where item will be inserted
        n = number of elements
        la[n] = linear array name
    */

    cout<< "Array: ";
    for(int i=0; i<n; i++){
        la[i] = rand() % 100; //creating random elements between 0 and 100 for la[n]
        cout << la[i] << " ";
    }
    cout << endl;
    
    //inserting into linear array
    int j = n;
    while (j >= k){
        la[j+1] = la[j]; //move array elements downwards from index=k
        j = j-1;
    }
    la[k] = item; //insert item at index=k
    n = n+1; //resize array


    cout << "Array after inserting at 4th index: ";
    for(int i=0; i<n; i++){
        cout << la[i] << " ";
    }
    cout << endl;
}