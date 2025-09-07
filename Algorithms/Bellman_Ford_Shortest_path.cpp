#include <bits/stdc++.h>
using namespace std;
using W = long long; const W INF=(1LL<<60);

struct Edge{int u,v; int w;};


// Bellman-Ford algorithm: single source shortest path

pair<vector<W>, bool> bellmanFord(int n, const vector<Edge>& edges, int src){
    vector<W> dist(n, INF); dist[src]=0;
    for(int i=1;i<=n-1;i++){
        bool any=false;
        for(auto e: edges){
            if(dist[e.u]==INF) continue;
            if(dist[e.v] > dist[e.u] + e.w){
                dist[e.v] = dist[e.u] + e.w;
                any=true;
            }
        }
        if(!any) break;
    }
    // detect negative cycle
    bool negCycle=false;
    for(auto e: edges){
        if(dist[e.u]!=INF && dist[e.v] > dist[e.u] + e.w){
            negCycle=true; break;
        }
    }
    return {dist, negCycle};
}

int main(){
    int n=5;
    vector<Edge> edges={{0,1,6},{0,2,7},{1,2,8},{1,3,5},{1,4,-4},{2,3,-3},{2,4,9},{3,1,-2},{4,3,7},{3,0,2}};
    auto result = bellmanFord(n, edges, 0);
    auto d = result.first;   // distances
    auto neg = result.second; // cycle flag

    cout<<"negCycle? "<<neg<<"\n";
    for(int i=0;i<n;i++) cout<<i<<":"<<(d[i]==INF? -1:d[i])<<"\n";
}
