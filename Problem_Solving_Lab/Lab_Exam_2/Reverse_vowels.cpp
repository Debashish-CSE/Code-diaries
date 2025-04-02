#include <bits/stdc++.h>

using namespace std;
int main(){
    string s = "hello world";
    cout << s << endl;
    queue<char> myqueue;
    stack<char> mystack;
    
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') myqueue.push(s[i]);            
    }

    while (!myqueue.empty()){
        mystack.push(myqueue.front());
        myqueue.pop();
    }

    while (!mystack.empty()){    
        myqueue.push(mystack.top());
        mystack.pop();
    } 
    
    cout << "After reversing vowels: " << endl;
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            cout << myqueue.front() ;
            myqueue.pop();
        }
        else cout<< s[i];
            
    }
   
    cout<<endl;

}