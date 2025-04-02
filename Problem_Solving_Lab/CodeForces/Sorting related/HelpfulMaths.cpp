//Link: https://codeforces.com/problemset/problem/339/As
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    vector<char> v;
    cin >> s;
    char temp;
    for(int i = 0; i < s.size(); i+=2){
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end());
    int j = 0;
    for(int i = 0; i < s.size(); i+=2){
        s[i] = v[j++];
    }
    cout << s << endl;
    return 0;
}