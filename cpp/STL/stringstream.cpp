#include <iostream>
#include <list>
#include <bits/stdc++.h>

using namespace std;

int main(){
    string S = "Dept. of CSE CU";
    stringstream SS(S);
    string eachword;
    list<string> csecu;
    while (SS >> eachword){
        csecu.push_back(eachword);
        cout << eachword << " ";
    }
    cout<< endl ;
    
    return 0;
}