#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    queue<char> q1;
    
    q1.push(str[0]);
    for (int i=1; i<str.size(); i++){
        bool found = false;
        for (int i=1; i<str.size(); i++){
            if(str[i] != q1.back()){
                found = true;
                break;
                }

                q1.push(q1.front());
                q1.pop();
            }

        if(!found){
            q1.push(str[i]);
        }
        
    }

    if(q1.empty()){
        cout<<"Empty string"<<endl;
    }

    while (!q1.empty()){
        cout<<q1.front()<<" ";
        q1.pop();
    }
    cout<<endl;

//input: azxxzy, output: ay

}