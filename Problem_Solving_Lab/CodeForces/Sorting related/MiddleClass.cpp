//Link: https://codeforces.com/contest/1334/problem/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, a, count;
        long long int sum;
        double avg;
        vector<int> v;
        cin >> n >> x;
        while(n--){
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());

        if(v[v.size()-1] >= x){
            sum = v[v.size()-1];
            count = 1;
            if(v.size()>1){
                for(int i = v.size()-2; i >=0 ; i--){
                    sum += (double)v[i];
                    avg = sum/(count+1);
                    if(avg < x){
                        break;
                    }
                    else{
                        count++;
                    }
                }
            }   
        }
        else{
            count = 0;
        }
        cout << count << endl;
    }
    return 0;
}