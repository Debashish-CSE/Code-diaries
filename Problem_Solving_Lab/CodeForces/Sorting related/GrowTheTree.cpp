//Link: https://codeforces.com/problemset/problem/1248/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a;
    long long int xx = 0, yy = 0, res = 0;
    vector<int> v, x, y;
    cin >> n;
    while(n--){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        if(i < v.size()/2){
            x.push_back(v[i]);
        }
        else{
            y.push_back(v[i]);
        }
    }
    for(int i = 0; i < x.size(); i++){
        xx += x[i];
    }
    for(int i = 0; i < y.size(); i++){
        yy += y[i];
    }
    res = (xx*xx) + (yy*yy);
    cout << res;
    return 0;
}