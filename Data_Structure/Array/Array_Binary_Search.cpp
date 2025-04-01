#include <iostream>

using namespace std;


//binary search algorithm
int main(){
    int data[] = {6,13,14,25,33,43,51,53,64,72,84,93,95,96,97};
    int lb = 0, ub = 14, beg=lb, end=ub, item = 33;
    int mid = (int) ((beg+end)/2);


    while((beg <= end) && (data[mid]!=item)){
        if(item < data[mid]) end = mid-1;
        else beg = mid+1;        
        mid = int((beg+end)/2); //set mid again for the next loop iteration
    }

    if(data[mid] == item) cout<< "Item found at the position "<< mid <<endl;
    else cout<< "Item is not in the list";
}