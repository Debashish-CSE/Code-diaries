#include <bits/stdc++.h>
using namespace std;
#define INF 1e9


//Floyd-Warshall algorithm - All pair shortest path

void floydWarshall(vector<vector<int>> &dist, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) dist[i][i] = 0;

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; // Convert 1-indexed to 0-indexed
        dist[u][v] = w;
    }

    floydWarshall(dist, n);

    cout << "\nShortest distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << "  ";
        }
        cout << endl ;
    }
}
