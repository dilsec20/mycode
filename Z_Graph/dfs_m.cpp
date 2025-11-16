#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;


int adj[N][N];
bool vis[N];

void dfs(int vertex, int n) {
    vis[vertex] = true;
    cout << vertex << " ";
 
    for (int i = 1; i <= n; ++i) {
      
        if (adj[vertex][i] == 1 && !vis[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;


    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    cout << "DFS traversal starting from node 1: ";
    dfs(1, n);
    cout << endl;
}