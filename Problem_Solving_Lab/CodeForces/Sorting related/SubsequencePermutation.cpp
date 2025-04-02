//Link:  https://codeforces.com/problemset/problem/1552/A
#include<bits/stdc++.h>
#define V(all) v.begin(),v.end()
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, count = 0;
        string a, b;
        cin >> n;
        cin >> a;

        b = a;
        sort(a.begin(), a.end());

        for(size_t i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                count++;
            }
        }
        
        cout << count << endl;

    }
    return 0;
}