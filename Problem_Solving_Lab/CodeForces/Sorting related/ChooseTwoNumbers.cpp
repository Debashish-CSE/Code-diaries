//Link: https://codeforces.com/problemset/problem/1206/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, m, b;
    vector<int> va, vb;
    cin >> n;
    while(n--){
        cin >> a;
        va.push_back(a);
    }
    cin >> m;
    while(m--){
        cin >> b;
        vb.push_back(b);
    }

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    cout << va[va.size()-1] << " " << vb[vb.size()-1] << endl;
    return 0;
}