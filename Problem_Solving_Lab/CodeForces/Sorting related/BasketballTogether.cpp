//Link: https://codeforces.com/problemset/problem/1725/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, d, x, sum = 0, count = 0, lim;
    vector<int> p;
    cin >> n >> d;
    while(n--){
        cin >> x;
        p.push_back(x);
    }
    sort(p.begin(), p.end());
    
    int mult = 2;
    int sub = 1;
    if(p.size() % 2 == 0){
        lim = (p.size())/2;
    }
    else{
        lim = ((p.size())/2) + 1;
    }

    for(int i = 0; i < p.size(); i++){
        if(p[i] > d){
            p.erase(p.begin()+i);
            count ++;
        }
    }
    if(!p.empty()){
        for(int i = 0; i < lim; i++){
            if(i!=p.size()-sub){
                sum = mult*p[p.size()-sub];
                if(sum>d){
                    count++;
                    sub++;
                    mult = 2;
                }
                else{
                    mult++;
                }
            }  
        }
    }
    
    cout << count << endl;
    return 0;
}