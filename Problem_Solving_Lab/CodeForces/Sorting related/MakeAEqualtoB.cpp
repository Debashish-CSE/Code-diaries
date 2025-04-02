//Link: https://vjudge.net/problem/CodeForces-1736A/origin
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, a, b;
        vector<int> va, vb;
        cin >> n;
        m = n;
        while(n--){
            cin >> a;
            va.push_back(a);
        }
        while(m--){
            cin >> b;
            vb.push_back(b);
        }

        if(va == vb){
            cout << 0 << endl;
        }
        else{
            int counta = 0, countb = 0, mone=0, x, y, ans;
            for(int i = 0; i < va.size(); i++){
                if(va[i] == 1){
                    counta++;
                }
                if(vb[i] == 1){
                    countb++;
                }
                if(va[i] == 1 && va[i]==vb[i]){
                    mone++; //Number of matching 1s
                }
            }

            if(counta == countb){
                cout << 1 << endl;
            }
            else{
                x = counta - mone; //unmatched 1s in A
                y = countb - mone; ////unmatched 1s in B
                ans = min(abs(x-y) + 1, max(x,y)); //min of rearrange+change and only changing
                cout << ans << endl;
            }   
        }
        
    }
    return 0;
}