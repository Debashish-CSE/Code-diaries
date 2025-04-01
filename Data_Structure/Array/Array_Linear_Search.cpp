#include <iostream>

using namespace std;

//linear search algorithm
int main(){
    int data[11] = {8,2,5,9,1,4,7,20,3,6}, n=10, item=20;
    
    data[n+1] = item;
    int loc = 0;

    while(data[loc] != item){
        loc++;
    }

    if(loc == n+1) loc=-1;
    
    if(loc == -1) cout<< "Item is not found" <<endl;
    else cout<< "Item found at the position " << loc <<endl;
}