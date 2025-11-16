#include<bits/stdc++.h>
using namespace std;

const int N  = 1e5+10;

vector<int> g[N];

bool vis[N];

vector<vector<int>> cc;
vector<int>current_cc;

void dfs(int vertex){

    vis[vertex] = true;
    current_cc.push_back(vertex);

    for(int child : g[vertex]){

        if(vis[child]) continue;

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
            current_cc.clear();
            dfs(i);
            cc.push_back(current_cc);
            count++;
        }
    }

    cout<<cc.size()<<'\n';
    
    for(auto c : cc){
        for(int ver : c){
            cout<<ver<<" ";
        }
        cout<<'\n';
    }

    for (int i = 0; i < cc.size(); i++) {
        cout << "Component " << i << " size = " << cc[i].size() << "\n";
    }

    
}