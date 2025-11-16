#include <bits/stdc++.h>
using namespace std;

int const N = 1e3 + 10;

int adj[N][N];
bool vis[N];

void bfs(int start, int n){

    queue<int>q;
    q.push(start);
    vis[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout<<node<<" ";

        for(int i= 1; i<=n; i++){
            if(adj[node][i] == 1 && !vis[i]){
                vis[i] = true;
                q.push(i);
            }
        }
    }

}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;

        adj[u][v]  = 1;
        adj[v][u] = 1;

    }

    bfs(1, n);
}