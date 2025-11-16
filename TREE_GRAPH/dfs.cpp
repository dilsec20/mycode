#include<bits/stdc++.h>
#include<queue>
using namespace std;

const int N = 1e5+10;

vector<int> g[N];
bool vis[N];

void dfs(int vertex){
    //action on vertex after entering in it
    cout<<vertex<<'\n';
    vis[vertex] = true;
    for(int child : g[vertex]){
        cout<<"parent"<<vertex<<", child"<<child<<'\n';
        //take action on child before entring in child node
        if(vis[child]) continue;

        dfs(child);
        //take action on child after exiting child node

    }
    //take action on vertex before exiting vertex
}

void bfs(int start_vertex) {
    for (int i = 0; i < N; ++i) { // Reset vis array for BFS
        vis[i] = false;
    }

    queue<int> q;
    q.push(start_vertex);
    vis[start_vertex] = true;

    cout << "\nBFS Traversal (Level by Level):\n";

    while (!q.empty()) {
        int current_vertex = q.front();
        q.pop();
        cout << current_vertex << '\n';

        for (int child : g[current_vertex]) {
            if (!vis[child]) {
                vis[child] = true;
                q.push(child);
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << "DFS Traversal (Deep First):\n";
    dfs(1); // Start DFS from vertex 1

    bfs(1); // Start BFS from vertex 1

}