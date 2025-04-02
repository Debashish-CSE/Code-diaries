#include <iostream>

using namespace std;

 //bubble sort algorithm
int main(){
    int n=6, data[6] = {77,42,35,12,101,5}, ptr, temp;

    //printing the previous array
    cout << "Previous array: ";
    for(int i=0; i<n; i++){
        cout<< data[i] << " ";
    }
    cout << endl;


    for(int k=1; k<=n-1; k++){
        ptr = 0;
        while(ptr <= n-k){
            if(data[ptr] > data[ptr+1]){
                temp = data[ptr];
                data[ptr] = data[ptr+1];
                data[ptr+1] = temp;
            }
            ptr++;
        }
    }

    cout << "After sorting the array: ";
    for(int i=0; i<n; i++){
        cout<< data[i] << " ";
    }
    cout << endl;
}