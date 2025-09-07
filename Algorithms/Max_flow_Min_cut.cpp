#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

// Edmonds-Karp algorithm: max flow and min cut
struct MaxFlow {
    int n; vector<vector<int>> cap, adj;
    MaxFlow(int n):n(n), cap(n, vector<int>(n,0)), adj(n){}
    
    void addEdge(int u,int v,int c){
        cap[u][v]+=c; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }

    int bfs(int s,int t, vector<int>& parent){
        fill(parent.begin(), parent.end(), -1);
        parent[s]=-2;
        queue<pair<int,int>> q; 
        q.push({s, INF});
        while(!q.empty()){
            auto p = q.front(); q.pop();
            int u = p.first, flow = p.second;
            for(int v: adj[u]){
                if(parent[v]==-1 && cap[u][v]>0){
                    parent[v]=u;
                    int new_flow=min(flow, cap[u][v]);
                    if(v==t) return new_flow;
                    q.push({v, new_flow});
                }
            }
        }
        return 0;
    }

    int maxflow(int s,int t){
        int flow=0, new_flow;
        vector<int> parent(n);
        while((new_flow=bfs(s,t,parent))){
            flow += new_flow;
            int v=t;
            while(v!=s){
                int u=parent[v];
                cap[u][v]-=new_flow;
                cap[v][u]+=new_flow;
                v=u;
            }
        }
        return flow;
    }

    // min cut: after maxflow, reachable from s in residual
    vector<pair<int,int>> minCutEdges(int s){
        vector<int> vis(n,0); 
        queue<int> q; 
        q.push(s); vis[s]=1;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v: adj[u]) 
                if(!vis[v] && cap[u][v]>0){ 
                    vis[v]=1; 
                    q.push(v); 
                }
        }
        vector<pair<int,int>> cut;
        for(int u=0;u<n;u++) 
            if(vis[u])
                for(int v: adj[u]) 
                    if(!vis[v] && cap[u][v]==0) 
                        cut.push_back({u,v}); // original saturated edges
        return cut;
    }
};

int main(){
    MaxFlow mf(6);
    mf.addEdge(0,1,16); mf.addEdge(0,2,13);
    mf.addEdge(1,2,10); mf.addEdge(2,1,4);
    mf.addEdge(1,3,12); mf.addEdge(2,4,14);
    mf.addEdge(3,2,9);  mf.addEdge(4,3,7);
    mf.addEdge(3,5,20); mf.addEdge(4,5,4);

    int flow = mf.maxflow(0,5);
    cout<<"Max flow="<<flow<<"\n";

    auto cut = mf.minCutEdges(0);
    cout<<"Min cut edges:\n";
    for(auto p : cut) {
        cout<<p.first<<"->"<<p.second<<"\n";
    }
}
