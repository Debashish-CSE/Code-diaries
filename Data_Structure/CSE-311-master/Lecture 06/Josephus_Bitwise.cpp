#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define PB push_back
#define All(V) V.begin(), V.end()
#define F first
#define S second
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void FASTIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
int main()
{
    FASTIO();
    int N;
    cin >> N;
    bitset<16> nb(N);
    string Str = nb.to_string();
    Str = Str.substr(Str.find("1") + 1) + "1";
    N = stoi(Str, nullptr, 2);
    cout << N << endl;
    return 0;
}