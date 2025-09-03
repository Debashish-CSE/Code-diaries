#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Compute Euler's Totient function
ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

// Fast modular exponentiation
ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    ll a, exp, mod;
    cout << "Enter base (a): ";
    cin >> a;
    cout << "Enter exponent (exp): ";
    cin >> exp;
    cout << "Enter modulus (mod): ";
    cin >> mod;

    // Check if a and mod are coprime
    if (__gcd(a, mod) != 1) {
        cout << a << " and " << mod << " are not coprime, Euler's theorem does not apply directly.\n";
        cout << a << "^" << exp << " mod " << mod << " = " << mod_pow(a, exp, mod) << " (computed directly).\n";
        return 0;
    }

    ll ph = phi(mod);
    cout << "Euler's Totient φ(" << mod << ") = " << ph << "\n";

    // Euler's theorem: a^exp mod mod = a^(exp % ph) mod mod if a, mod coprime
    ll reduced_exp = exp % ph;
    cout << "Exponent reduced by Euler's theorem: " << reduced_exp << "\n";

    ll res = mod_pow(a, reduced_exp, mod);
    cout << a << "^" << exp << " mod " << mod << " = " << res << "\n";
}