//Link: https://codeforces.com/contest/1360/problem/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n;
        vector<int> v;
        while(n--){
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        int diff = v[1] - v[0];
        for(int i = 0; i < v.size()-1; i++){
            if(v[i+1] == v[i]){
                diff = 0;
                break;
            }
            if(v[i+1]-v[i] < diff){
                diff = v[i+1]-v[i];
            }
        }
        cout << diff << endl;
    }
    return 0;
}