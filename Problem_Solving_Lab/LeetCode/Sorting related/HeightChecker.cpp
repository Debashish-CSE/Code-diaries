//Link: https://leetcode.com/problems/height-checker/
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    sort(v.begin(), v.end());
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] != v[i]) count++;
    }
    cout << count;
    return 0;
}