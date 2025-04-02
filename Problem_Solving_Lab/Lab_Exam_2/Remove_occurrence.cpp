#include <bits/stdc++.h>
#include <stack>

using namespace std;

void rem_occ(stack<int> st1, int item){
    stack<int> st2;

    while(!st1.empty()){
       if(st1.top() != item){
            int top = st1.top();
            st2.push(top);
            st1.pop();
        }
        else{
            st1.pop();
        } 
    }
    
    while(!st2.empty()){
        cout << st2.top() << " ";
        st2.pop();
    }
}


int main(){
    stack<int> st1;
    int item = 2;
    int nums[5] = {5,2,7,2,10};

    for(int i=0; i<5; i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    
    for(int i=0; i<5; i++){
        st1.push(nums[i]);
    }
    /*while (!st1.empty()) {
        cout<< st1.top() << " ";
        st1.pop();
    }*/
    cout << endl << "After removing the occurences of 2: ";
    rem_occ(st1, item);
    cout << endl;

}