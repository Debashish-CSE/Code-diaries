//Link: https://codeforces.com/contest/1430/problem/B
#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int main(){
    int m;
    cin >> m;
    while(m--){
        vector<int> br;
        int n, k, x=0;
        long long int diff=0;
        cin >> n >> k;
        while(n--){
            cin >> x;
            br.push_back(x);
        }
        sort(br.begin(), br.end(), comp);
        diff = br[0];
        for(int i = 1; i <=k; i++){
            diff+=br[i];
        }
        cout << diff << endl;
    }
    return 0;
}