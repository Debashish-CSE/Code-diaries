#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1,s2;
    cout<<"Enter s1: ";
    cin>>s1;
    cout<<"Enter s2: ";
    cin>>s2;
    /*s1 = "geee#e#ks";
    s2 = "gek##eeks";*/
    
    stack<char> st1,st2;
    for(int i=0; i<s1.size(); i++){
        if (!st1.empty() && s1[i]=='#'){
            st1.pop();       
        }
        else {
            st1.push(s1[i]);
        }
    }
    for(int i=0; i<s2.size(); i++){
        if (!st2.empty() && s2[i]=='#'){
            st2.pop();       
        }
        else {
            st2.push(s2[i]);
        }
    }

    /*while (!st1.empty()){
        cout<<st1.top()<<" ";
        st1.pop();
    }
    cout<<endl;

    while (!st2.empty()){
        cout<<st2.top()<<" ";
        st2.pop();
    }
    cout<<endl;*/

    int flag = 0;
    while (!st1.empty() && !st2.empty()){
        if(st1.top()!=st2.top()){
            flag++;
        }
        st1.pop();
        st2.pop();
    }
    
    
    if(flag == 0) cout<<"True"<<endl;
    else cout<<"False"<<endl;

}