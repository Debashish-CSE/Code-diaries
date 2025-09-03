#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isprime(ll a){
    bool flag = true;
    if (a == 0) flag = false;
    if (a == 1) flag = false;
    for (int i=2; i<=sqrt(a); i++){
        if(a % i == 0){
        flag = false;
        break;
        }
    }
    return flag;
}

ll gcd(ll a, ll b){
    ll rem;
    while (b != 0){
        rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

// a^b mod m
ll mod(ll a, ll b, ll m) {
    ll result = 1;
    a %= m;
    while (b > 0) {
        if (b & 1)
            result = (result * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return result;
}

// Fermat's Little Theorem
ll fermat(ll a, ll p) {
    if (a % p == 0) {
        cout << "a divisible by p\n";
        return -1;
    }
    return mod(a, p - 2, p); // a^(p-2) mod p
}


ll phi(ll m) {
    ll result = m;
    for (ll i = 2; i * i <= m; ++i) {
        if (m % i == 0) {
            while (m % i == 0)
                m /= i;
            result -= result / i;
        }
    }
    if (m > 1)
        result -= result / m;
    return result;
}

ll euler(ll a, ll m) {
    if (__gcd(a, m) != 1) {
        cout << "a and m are not coprime\n";
        return -1;
    }
    ll phi_m = phi(m);
    return mod(a, phi_m - 1, m); // a^(φ(m)-1) mod m
}


int main(){
    ll a,b,m;
    cout << "Enter a, b & mod: ";
    cin >> a >> b >> m;
    cout << "gcd: " << __gcd(a,m) << endl;
    cout << "mod: " << mod(a,b,m) << endl;
    cout << "fermat: " << fermat(a,m) << endl;
    cout << "euler: " << euler(a, m) << endl;

}