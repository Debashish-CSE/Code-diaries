//Link: https://codeforces.com/problemset/problem/37/A
#include<bits/stdc++.h>
#define V(all) v.begin(),v.end()
using namespace std;

int main(){
    int n, a, x, count = 0, height = 0, num = 0;
    cin >> n;
    vector<int> v;
    while(n--){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    x = v[0];
    if(x>0){
        count = 1;
        num = 1;
    }
    for(int i = 1; i < v.size(); i++){
        if(x==v[i]){
            count++;
        }
        else{
            x = v[i];
            num++;
            if(count > height){
                height = count;
            }
            if(x>0){
                count = 1;
            }
            else{
                count = 0;
            }
        }

    }
    if(count > height){
        height = count;
    }
    cout << height << " " << num << endl;
    return 0;
}