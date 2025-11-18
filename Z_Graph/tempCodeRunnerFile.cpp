class Solution {
public:
    vector<int> vis, rec;

    bool dfs(int u, vector<vector<int>>& adj) {
        vis[u] = 1;
        rec[u] = 1;

        for (int v : adj[u]) {
            if (!vis[v]) {
                if (dfs(v, adj)) return true;
            } 
            else if (rec[v]) {
                return true;   // cycle detected
            }
        }

        rec[u] = 0;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        // build adjacency list: b -> a
        vector<vector<int>> adj(n);
        for (auto& pr : prerequisites) {
            adj[pr[1]].push_back(pr[0]);
        }

        vis.assign(n, 0);
        rec.assign(n, 0);

        // run DFS on each unvisited node
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, adj)) return false;  // if cycle exists → cannot finish
            }
        }

        return true;  // no cycle → can finish all courses
    }
};
