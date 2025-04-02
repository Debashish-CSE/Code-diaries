//Link: https://codeforces.com/problemset/problem/230/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    int s, n, x, y;
    map<int, int> xyMap;
    cin >> s >> n;
    while(n--){
        cin >> x >> y;
        if(xyMap.find(x)==xyMap.end()){
            xyMap[x]=y;
        }
        else{
            xyMap[x]+=y;
        }
        
    }
    
    int score = s;
    bool win = true;
    for(auto a: xyMap){
        if(score > a.first){
            score += a.second;
        }
        else{
            win = false;
            break;
        }
    }    
    
    if(win == true){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}