#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)

const int MAX_NODES = 100005;
const int MAX_AHO_NODES = 1000006;

struct Query {
    int v_tribe, id;
};

vi tribe_adj[MAX_NODES];
int tribe_tin[MAX_NODES], tribe_tout[MAX_NODES], tribe_timer;

vi aho_fail_adj[MAX_AHO_NODES];
int aho_tin[MAX_AHO_NODES], aho_tout[MAX_AHO_NODES], aho_timer;
int term_nodes[MAX_NODES]; 

vector<Query> queries_by_text[MAX_NODES];
ll query_ans[MAX_NODES];

int trie[MAX_AHO_NODES][26];
int link[MAX_AHO_NODES];
int trie_nodes = 1;

ll bit[MAX_AHO_NODES];

void bit_update(int idx, int delta) {
    for (; idx <= trie_nodes; idx += idx & -idx) {
        bit[idx] += delta;
    }
}

ll bit_query(int idx) {
    ll sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

ll bit_range_query(int l, int r) {
    if (l > r) return 0;
    return bit_query(r) - bit_query(l - 1);
}

void add_string(const string& s, int tribe_id) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'A';
        if (!trie[v][c]) {
            trie[v][c] = trie_nodes++;
        }
        v = trie[v][c];
    }
    term_nodes[tribe_id] = v;
}

void build_aho() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int c = 0; c < 26; ++c) {
            if (trie[v][c]) {
                link[trie[v][c]] = v == 0 ? 0 : trie[link[v]][c];
                q.push(trie[v][c]);
            } else {
                trie[v][c] = v == 0 ? 0 : trie[link[v]][c];
            }
        }
    }
}

void dfs_tribe(int v) {
    tribe_tin[v] = ++tribe_timer;
    for (int u : tribe_adj[v]) {
        dfs_tribe(u);
    }
    tribe_tout[v] = tribe_timer;
}

void dfs_aho(int v) {
    aho_tin[v] = ++aho_timer;
    for (int u : aho_fail_adj[v]) {
        dfs_aho(u);
    }
    aho_tout[v] = aho_timer;
}

     
                /*  JAY SHREE RAM  */

void solve() {
    int n;
    int q;
    cin >> n >> q;
    vector<string> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        add_string(s[i], i);
    }

    build_aho();

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tribe_adj[u].push_back(v);
    }

    dfs_tribe(1);

    for (int i = 1; i < trie_nodes; ++i) {
        aho_fail_adj[link[i]].push_back(i);
    }
    dfs_aho(0);

    vector<pii> tribe_queries[q];
    map<string, int> text_to_id;
    int text_id_counter = 0;

    for (int i = 0; i < q; ++i) {
        int v;
        string t;
        cin >> v >> t;
        if (text_to_id.find(t) == text_to_id.end()) {
            text_to_id[t] = text_id_counter++;
        }
        int text_id = text_to_id[t];
        queries_by_text[text_id].push_back({v, i});
    }

    for (const auto& pair : text_to_id) {
        const string& text_str = pair.first;
        int text_id = pair.second;

        int v = 0;
        for (char ch : text_str) {
            v = trie[v][ch - 'A'];
            bit_update(aho_tin[v], 1);
        }

        for (const auto& query : queries_by_text[text_id]) {
            int tribe_v = query.v_tribe;
            ll total_matches = 0;
            for (int i = tribe_tin[tribe_v]; i <= tribe_tout[tribe_v]; ++i) {
                int aho_node = term_nodes[i];
                total_matches += bit_range_query(aho_tin[aho_node], aho_tout[aho_node]);
            }
            query_ans[query.id] = total_matches;
        }

        v = 0;
        for (char ch : text_str) {
            v = trie[v][ch - 'A'];
            bit_update(aho_tin[v], -1);
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << query_ans[i] << "\n";
    }
}

int main() {
    fast_io;
    solve();
    return 0;
}
