//Link: https://codeforces.com/problemset/problem/1669/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, a, base, count = 0;
        vector<int> v;
        cin >> n;
        while(n--){
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());

        if(v.size() >= 3){

            base = v[0];
            for(int i = 1; i < v.size(); i++){
                if(base == v[i]){
                    count++;
                }
                else{
                    count = 0;
                    base = v[i];
                }
                if(count == 2){
                    break;
                }
            }
            if(count == 2){
                cout << base << endl;
            }
            else{
                cout << -1 << endl;
            }

        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}