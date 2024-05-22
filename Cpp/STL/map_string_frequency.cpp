#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;
int main(){
    string s1 = "learning to code is learning to create and innovate";
    string eachword;
    stringstream ss(s1);
    int k=1;
    map<string, int> m;
    while (ss >> eachword){
        if(m.find(eachword)==m.end())
            m[eachword] = k;
        else
            m[eachword]++;
    }
    
    for (auto st: m){
        cout<< st.first << " " << st.second <<"\n";
    }

}