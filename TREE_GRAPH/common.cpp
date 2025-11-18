#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 4e18;

int N, Q, S;
vector<vector<pair<int,ll>>> g;

void build1(int n, int l, int r, int offset) {
    int id = n + offset;
    if(l == r) return;
    int mid = (l + r) / 2;
    g[id].push_back({n*2 + offset, 0});
    g[id].push_back({n*2+1 + offset, 0});
    build1(n*2, l, mid, offset);
    build1(n*2+1, mid+1, r, offset);
}
void build2(int n, int l, int r, int offset) {
    int id = n + offset;
    if(l == r) return;
    int mid = (l + r) / 2;
    g[n*2 + offset].push_back({id, 0});
    g[n*2+1 + offset].push_back({id, 0});
    build2(n*2, l, mid, offset);
    build2(n*2+1, mid+1, r, offset);
}

void add1(int n, int l, int r, int ql, int qr, int x, ll w, int offset){
    if(qr < l || r < ql) return;
    if(ql <= l && r <= qr){
        g[x].push_back({n + offset, w});
        return;
    }
    int mid=(l+r)/2;
    add1(n*2, l, mid, ql, qr, x, w, offset);
    add1(n*2+1, mid+1, r, ql, qr, x, w, offset);
}
void add2(int n, int l, int r, int ql, int qr, int x, ll w, int offset){
    if(qr < l || r < ql) return;
    if(ql <= l && r <= qr){
        g[n + offset].push_back({x, w});
        return;
    }
    int mid=(l+r)/2;
    add2(n*2, l, mid, ql, qr, x, w, offset);
    add2(n*2+1, mid+1, r, ql, qr, x, w, offset);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q >> S;
    
    int base = 1;
    while(base < N) base <<= 1;

    
    int out_tree_offset = N + 1;
    int in_tree_offset = out_tree_offset + 2 * base;
    int SZ = in_tree_offset + 2 * base + 5;
    g.resize(SZ);

    build1(1, 1, base, out_tree_offset);
    build2(1, 1, base, in_tree_offset);

    
    for(int i=1;i<=N;i++){
       
        g[base + i - 1 + out_tree_offset].push_back({i, 0});
    
        g[i].push_back({base + i - 1 + in_tree_offset, 0});
    }

    while(Q--){
        int t; cin >> t;
        if(t == 1){
            int a,b; ll w;
            cin >> a >> b >> w;
            g[a].push_back({b, w});
        }
        else if(t == 2){
            int v,l,r; ll w;
            cin >> v >> l >> r >> w;
            add1(1, 1, base, l, r, v, w, out_tree_offset);
        }
        else{
            int v,l,r; ll w;
            cin >> v >> l >> r >> w;
            add2(1, 1, base, l, r, v, w, in_tree_offset);
        }
    }

    vector<ll> dist(SZ, INF);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;

    dist[S] = 0;
    pq.push({0,S});

    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        for(auto &e:g[u]){
            int v=e.first; ll w=e.second;
            if(dist[v]>d+w){
                dist[v]=d+w;
                pq.push({dist[v],v});
            }
        }
    }

    for(int i=1;i<=N;i++)
        cout << (dist[i] >= INF ? -1 : dist[i]) << " ";
}
