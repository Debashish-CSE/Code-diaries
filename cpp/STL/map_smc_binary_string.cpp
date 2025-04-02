#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <map>

using namespace std;

int main() {
    string x, y;

    // Input two binary strings
    cout << "Enter the first binary string: ";
    cin >> x;
    cout << "Enter the second binary string: ";
    cin >> y;

    // Check if the lengths of both strings are equal
    if (x.length() != y.length()) {
        cout << "Error: Binary strings must have equal lengths." << endl;
        return 1;
    }

    map<string, int> m;
    string a ="f01", b="f10", c="f11", d="f00"; 
    m[a]=0, m[b]=0, m[c]=0, m[d]=0;
    for (size_t i = 0; i < x.length(); ++i){
        
        if (x[i] == '0' && y[i] == '1') {
            m[a]++;
        } 
        else if (x[i] == '1' && y[i] == '0') {
            m[b]++;
        } 
        else if (x[i] == '1' && y[i] == '1') {
            m[c]++;
        } 
        else if (x[i] == '0' && y[i] == '0') {
            m[d]++;
        }
    }
    
    for(auto st:m){
        cout<<st.first<<" "<<st.second<<endl;
    }

    // Calculate SMC using the formula: SMC = (f11 + f00) / (f01 + f10 + f11 + f00)
    double numerator = (m[c] + m[d]);
    double denominator = (m[a] + m[b] + m[c] + m[d]);
    double smc = numerator / denominator;

    cout << "Simple Matching Coefficient (SMC): " << smc << endl;

    return 0;


}