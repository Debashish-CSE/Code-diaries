//Link: https://codeforces.com/contest/1760/problem/C
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s;
        vector<int> v, z;
        cin >> n;
        while(n--){
            cin >> s;
            v.push_back(s);
        }
        z = v;
        sort(v.begin(), v.end());
        int largest = v[v.size()-1];
        int large = v[v.size()-2];

        for(int i = 0; i < z.size(); i++){
            if(z[i]==largest){
                cout << z[i]-large << " ";
            }
            else{
                cout << z[i] - largest << " ";
            }
        }
        cout << endl;

    }
    return 0;
}