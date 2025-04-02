//Link: https://codeforces.com/problemset/problem/160/A
#include<bits/stdc++.h>
#define V(all) v.begin(),v.end()
using namespace std;

int sum(vector<int> &v, int pos){
    int sum = 0;
    for(int i = 0; i <= pos; i++){
        sum += v[i];
    }
    return sum;
}

int main(){
    int n, a, totl = 0, cnt = 0;
    cin >> n;
    vector<int> v;
    while(n--){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    for(int i = v.size()-1; i >=0; i--){
        totl += v[i];
        cnt++;
        if(totl > sum(v, i-1)){
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}