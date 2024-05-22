#include <bits/stdc++.h>

using namespace std;
int main(){
    string s = "Technical Interview Preparation";
    cout <<s <<endl;
    string eachword;
    queue<string> myqueue;
    stack<string> mystack;
    stringstream s1(s);
    while ( s1 >> eachword ){
        myqueue.push(eachword);
        
    }

    while (!myqueue.empty()){
        mystack.push(myqueue.front());
        myqueue.pop();
    }
    while (!mystack.empty()){
        
        myqueue.push(mystack.top());
        mystack.pop();
    }
    while (!myqueue.empty()) {
        cout<<myqueue.front()<<" ";    
        myqueue.pop();
    }
    cout<<endl;

}