#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int Mod(int a, int k, int mod) {
    int result = 1;
    a %= mod;
    for (int i = 0; i < k; ++i)
        result = (result * a) % mod;
    return result;
}

int superPow(int a, vector<int>& b) {
    int mod = 1337;
    int result = 1;
    for (int digit : b) {
        result = Mod(result, 10, mod) * Mod(a, digit, mod) % mod;
    }
    return result;
}

int main() {
    int a;
    vector<int> b;
    cout << "a: ";
    cin >> a;
    cout <<endl << "B array: ";

    for (int i : b){
        cin >> i;
    }
    cout << "a^b(mod 1337): "<< superPow(a, b);

    return 0;
}
