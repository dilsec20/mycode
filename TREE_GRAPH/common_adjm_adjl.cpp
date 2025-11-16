#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int graph[N][N];            // adjacency matrix
vector<int> graph2[N];      // adjacency list

int main() {
    int n, m;
    cin >> n >> m;

    // Input edges
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        // For adjacency matrix
        graph[v1][v2] = 1;
        graph[v2][v1] = 1; // undirected

        // For adjacency list
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);
    }

    // ---------------------------------------------
    cout << "\nAdjacency Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    // ---------------------------------------------
    cout << "\nAdjacency List:\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int v : graph2[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}
