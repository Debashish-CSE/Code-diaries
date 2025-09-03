#include <iostream>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll modPow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int countGoodNumbers(int n) {
    int evenPos = (n + 1) / 2;
    int oddPos = n / 2;
    return (modPow(5, evenPos, MOD) * modPow(4, oddPos, MOD)) % MOD;
}

int main() {
    int n;
    cin >> n;
    cout << countGoodNumbers(n) << endl;
    return 0;
}
