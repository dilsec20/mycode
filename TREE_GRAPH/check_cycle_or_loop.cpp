#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

vector<vector<int>> cc;   // to store all connected components
vector<int> current_cc;

// ---------- DFS to detect cycle ----------
bool dfs_cycle(int vertex, int parent) {
    vis[vertex] = true;
    current_cc.push_back(vertex);

    for (int child : g[vertex]) {
        if (!vis[child]) {
            if (dfs_cycle(child, vertex))
                return true;  // cycle found deeper
        } 
        else if (child != parent) {
            // visited child not equal to parent => cycle
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool hasCycle = false;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            current_cc.clear();
            bool cycle_in_this_component = dfs_cycle(i, -1);
            cc.push_back(current_cc);

            if (cycle_in_this_component)
                hasCycle = true;
        }
    }

    cout << "Total components: " << cc.size() << "\n\n";

    for (int i = 0; i < cc.size(); i++) {
        cout << "Component " << i + 1 << " -> ";
        for (int v : cc[i]) cout << v << " ";
        cout << " | size = " << cc[i].size() << "\n";
    }

    cout << "\nCycle present in graph? ";
    if (hasCycle) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}



//Direceted 
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
bool inRecursion[N];   // to track recursion stack
vector<vector<int>> cc;
vector<int> current_cc;

// ---------- DFS for directed graph ----------
bool dfs_directed_cycle(int vertex) {
    vis[vertex] = true;
    inRecursion[vertex] = true;
    current_cc.push_back(vertex);

    for (int child : g[vertex]) {
        if (!vis[child]) {
            if (dfs_directed_cycle(child))
                return true;  // found cycle in deeper call
        }
        else if (inRecursion[child]) {
            // found a back edge => cycle exists
            return true;
        }
    }

    inRecursion[vertex] = false;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); // directed edge
    }

    bool hasCycle = false;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            current_cc.clear();
            bool cycle_here = dfs_directed_cycle(i);
            cc.push_back(current_cc);
            if (cycle_here)
                hasCycle = true;
        }
    }

    cout << "Total components (reachable subgraphs): " << cc.size() << "\n\n";

    for (int i = 0; i < cc.size(); i++) {
        cout << "Component " << i + 1 << " -> ";
        for (int v : cc[i]) cout << v << " ";
        cout << " | size = " << cc[i].size() << "\n";
    }

    cout << "\nCycle present in directed graph? ";
    if (hasCycle) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
