//Link: https://codeforces.com/contest/1380/problem/C
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, a, skill, count = 0;
        vector<int> v, vd;
        cin >> n >> x;
        while(n--){
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        int len = v.size();
        for(int i = len-1; i >=0; i--){
            vd.push_back(v[i]);
        }
        int mult = 1;
        for(int j=0; j<len; j++){
            skill = vd[j]*mult;
            if(skill >= x){
                count++;
                mult = 1;
            }
            else{
                mult++;
            }
        }
        cout << count << endl;
    }
    return 0;
}