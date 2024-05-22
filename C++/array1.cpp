#include <iostream>

using namespace std;

int main(){
    int arr[5];
    for (int i=0; i<5; i++){
        cout<<"Enter the "<<i+1<<"th number: ";
        cin>>arr[i];
    }
    for (int i=0; i<5; i++){
        cout<<i+1<<"th number is: "<<arr[i]<<endl;
    }

    return 0;
}