#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
    const long long INF = 1e18;

    vector<long long> dist(n, INF);
    dist[src] = 0;

    priority_queue<pair<long long,int>, 
                   vector<pair<long long,int>>, 
                   greater<pair<long long,int>>> pq;

    pq.push({0, src});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d != dist[u]) continue;   // stale pair check

        for(auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed graph
    }

    int src;
    cin >> src;
    src--;

    vector<long long> dist = dijkstra(n, adj, src);

    for(int i = 0; i < n; i++)
        cout << dist[i] << " ";
}
