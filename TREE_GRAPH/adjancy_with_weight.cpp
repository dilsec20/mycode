#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int graph[N][N];

vector<pair<int,int>> graph2[N];

int main(){
    int n,m;
    cin>>n>>m;

    for(int i = 0; i<m; i++){
        int v1,v2, w;
        cin>>v1>>v2>>w;

        graph[v1][v2] == w;
        graph[v2][v1] == w;

        graph2[v1].push_back({v2, w});
        graph2[v2].push_back({v1, w});
    }

    if(graph[i][j] == 1 ){
        cout<<"Connected";
    }

    return 0;
}