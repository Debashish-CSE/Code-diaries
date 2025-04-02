//Link: https://codeforces.com/contest/1339/problem/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,a;
        vector<int> v;
        cin >> n;
        int m = n;
        while(m--){
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());

        int l = (n/2) - 1;
        int r = n/2;
        for(int i = 0; i < n/2; i++){
            cout << v[r++] << " " << v[l--] << " ";
        }
        if(n%2!=0){
            cout << v[n-1];
        }
        cout << endl;
    }
    return 0;
}