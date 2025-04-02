//Link: https://codeforces.com/contest/1760/problem/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x,y,z;
        cin >> x >> y >> z;
        if(x>y && x>z){
            if(y>z){
                cout << y << endl;
            }
            else{
                cout << z << endl;
            }
        }
        else if(y>x && y>z){
            if(x>z){
                cout << x << endl;
            }
            else{
                cout << z << endl;
            }
        }
        else if(z>x && z>y){
            if(x>y){
                cout << x << endl;
            }
            else{
                cout << y << endl;
            }
        }
    }
    return 0;
}