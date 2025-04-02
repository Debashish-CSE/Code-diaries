//Link: https://codeforces.com/problemset/problem/1399/A
#include<bits/stdc++.h>
#define V(all) v.begin(),v.end()
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, a;
        vector<int> v, z(1);
        cin >> n;
        while(n--){
            cin >> a;
            v.push_back(a);
        }

        sort(v.begin(), v.end());

        if(v.size()>1){
            for(int i = 0; i < v.size()-1; i++){
                if(v[i+1]-v[i] <= 1 || v[i+1] == v[i]){
                    z[0] = v[i+1];
                }
                else{
                    z[0] = -1;
                    break;
                }
            }
            if(z[0] != -1){
                cout << "YES" << endl;
            }
            else{
            cout << "NO" << endl;
            }
        }
        else{
            cout << "YES" << endl;
        }    
    }
    return 0;
}