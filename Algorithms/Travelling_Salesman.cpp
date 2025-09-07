#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int tsp_heldKarp(const vector<vector<int>>& w){
    int n=w.size(), N=1<<n;
    vector<vector<int>> dp(N, vector<int>(n, INF));
    dp[1<<0][0]=0;
    for(int mask=0; mask<N; mask++){
        for(int u=0; u<n; u++) if(dp[mask][u]<INF){
            for(int v=0; v<n; v++) if(!(mask&(1<<v))){
                dp[mask|(1<<v)][v] = min(dp[mask|(1<<v)][v], dp[mask][u] + w[u][v]);
            }
        }
    }
    int ans=INF;
    for(int u=1; u<n; u++) ans=min(ans, dp[N-1][u] + w[u][0]); // return to start
    return ans;
}

int main(){
    vector<vector<int>> w={{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};
    cout<<"TSP cost="<<tsp_heldKarp(w)<<"\n";
}
