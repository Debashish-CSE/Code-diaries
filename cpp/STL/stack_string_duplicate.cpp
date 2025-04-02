#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    stack<char> s1;
    for(int i=str.size(); i>=0; i--){
        if (!s1.empty() && str[i]==s1.top()){
            s1.pop();
            
        }
        else {
            s1.push(str[i]);
        }
    }

    if(s1.empty()){
        cout<<"Empty string"<<endl;
    }

    while (!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;

//input: azxxzy, output: ay

}