#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;

    while (exp > 0) {
        
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ll a, p, k;
    cout << "Enter base a, exponent k,Mod p(a^k mod k): ";
    cin >> a >> k>>p;

    // Using Fermat's Little Theorem to reduce exponent modulo p-1
    ll reduced_exp = k % (p - 1);

    cout << a << "^" << k << " mod " << p << " = " << mod_pow(a, reduced_exp, p) << "\n";
}
