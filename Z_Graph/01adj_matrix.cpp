#include <bits/stdc++.h>
using namespace std;

int const N = 1e3+5;
int graph[N][N];

int main(){
    int n,m;
    cin>>n>>m;

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;

        graph[u][v] = 1;
        graph[v][u] = 1;

    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<'\n';

    }
    return 0;
}