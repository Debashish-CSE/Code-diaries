//Link: https://codeforces.com/problemset/problem/937/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, x, count = 0;
    cin >> n;
    vector<int> v;
    while(n--){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    x = v[v.size()-1];
    if(x!=0){
        count++;
    }
    for(int i = v.size()-2; i >= 0; i--){
        x = v[i];
        if(x!=0 && x!=v[i+1]){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}