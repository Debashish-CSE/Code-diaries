//Link: https://codeforces.com/problemset/problem/1725/B
#include<bits/stdc++.h>
using namespace std;
using ll        = long long;
int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    int ans = 0;
    ll cur = 0;
    int x = 0;
    while(l <= r) {
        if (!x) {
            x = v[r--];
            cur = x;
        } else {
            cur += x;
            l++;
        }
        if (cur > d) {
            ans++;
            cur = 0;
            x = 0;
        }
    }
    cout << ans;
    return 0;
}

