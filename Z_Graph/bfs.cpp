#include<bits/stdc++.h>
using namespace std;

int const N = 1e5+10;

vector<int> g[N];
bool vis[N];

void bfs(int start){

    queue<int> q;
    q.push(start);
    vis[start] = true;

    while(!q.empty()){
        int vertex = q.front();
        q.pop();

        cout<<vertex<<" ";

        for(int child : g[vertex]){
            if(!vis[child]){
                vis[child] = true;
                q.push(child);
            }
        }
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

    for(int i = 1; i<=n;i++){
        if(!vis[i]){
            bfs(i);
            count++;
            cout<<'\n';
        }
    }

    cout<<<<count;
    return 0;



}