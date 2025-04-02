//Link: https://codeforces.com/problemset/problem/723/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y,z;
    cin >> x >> y >> z;
    vector<int> pts;
    pts.push_back(x);
    pts.push_back(y);
    pts.push_back(z);

    sort(pts.begin(), pts.end());
    cout << pts[2] - pts[0];
    return 0;
}