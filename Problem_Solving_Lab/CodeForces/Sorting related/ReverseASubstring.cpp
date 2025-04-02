//Link: https://codeforces.com/problemset/problem/1155/A
#include<bits/stdc++.h>
#define V(all) v.begin(),v.end()
using namespace std;

int main(){
    int n, count = 0;
    cin >> n;
    string s;
    cin >> s;
    for(size_t i = 0; i < s.size()-1; i++){
        if(s[i]>s[i+1]){
            cout << "YES" << endl;
            cout << i+1 << " " << i+2 << endl;
            break;
        }
        else{
            count++;
        }
    }
    if(count == s.size()-1){
        cout << "NO" << endl;
    }
    return 0;
}