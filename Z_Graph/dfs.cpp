#include <bits/stdc++.h>
using namespace std;

int const N = 1e5+10;

vector<int> g[N];
bool vis[N];

void dfs(int vertex){

    vis[vertex] = true;
    cout<<vertex<<" ";
    

    for(int child : g[vertex]){
        if(!vis[child])
        dfs(child);
    }
    
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int count = 0;
    
    for(int i = 1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
            count++;
            cout<<'\n';
        }

    }

    cout<<"component "<< count;

    return 0;
}