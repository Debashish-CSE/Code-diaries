//Link: https://codeforces.com/problemset/problem/1676/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, a;
        vector<int> v;
        cin >> n;
        while(n--){
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        int count = 0;
        for(int i = v.size()-1; i >=1; i--){
            count+=v[i]-v[0];
        }
        cout << count << endl;
    }
    return 0;
}