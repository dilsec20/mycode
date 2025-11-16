#include <bits/stdc++.h>
using namespace std;

int const N = 1e5+10;

vector<int> g[N];
vector<int> dis(N, -1);


void bfs_path(int start){
    queue<int>q;
    q.push(start);
    
   

    dis[start] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();


        for(int child : g[node]){
            if(dis[child] == -1){
                dis[child] = dis[node] + 1;
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

    bfs_path(1);
   

    int shortest_path = 0;
    for(int i = 1; i <= n; i++){
        shortest_path += dis[i];
    }
    cout << shortest_path<<endl;


    return 0;
}