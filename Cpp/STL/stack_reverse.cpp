#include <bits/stdc++.h>

using namespace std;
int main(){
    string s = "Technical Interview Preparation";
    cout <<s <<endl;
    string eachword;
    stack<string> mystack;
    stringstream s1(s);
    while ( s1 >> eachword){
        mystack.push(eachword);
    }

    while (!mystack.empty()){
        cout << mystack.top() <<" ";
        mystack.pop();
    }
    cout<<endl;

}