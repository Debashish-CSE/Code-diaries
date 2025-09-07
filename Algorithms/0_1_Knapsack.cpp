#include <bits/stdc++.h>
using namespace std;

int knap01(const vector<int>& wt, const vector<int>& val, int W){
    vector<int> dp(W+1, 0);
    for(size_t i=0;i<wt.size();++i)
        for(int w=W; w>=wt[i]; --w)
            dp[w] = max(dp[w], dp[w-wt[i]] + val[i]);
    return dp[W];
}

int main(){
    vector<int> wt={10,20,30}, val={60,100,120};
    cout<<knap01(wt,val,50)<<"\n";
}
