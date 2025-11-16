#include <bits/stdc++.h>
using namespace std;

int const N = 1e3+5;
vector<int> g[N];

int main(){ 
    int n,m;
    cin>>n>>m;

    for(int i = 0; i<m;i++){
        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);

    }

    for(int i =1; i<=n;i++){
        cout<<i<<" -> ";
        for(auto v:g[i]){
            cout<<v<<" ";
        }

        cout<<'\n';
    }

    return 0;
}
