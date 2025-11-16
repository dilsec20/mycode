#include <iostream>
#include <vector>
#include <queue>
#include <limits> // For numeric_limits

using namespace std;

const int N = 1e5 + 10;
const long long INF = numeric_limits<long long>::max(); // Using long long for infinity

vector<pair<int, int>> g[N]; // Adjacency list: stores {child_vertex, weight}
long long dist[N]; // Distance array: stores shortest distance from source to each vertex

void dijkstra(const vector<int>& hospital_locations, int n) {
    for (int i = 1; i <= n; ++i) {
        dist[i] = INF; // Initialize all distances to infinity
    }

    // Priority queue stores pairs of {distance, vertex}
    // It's a min-heap, so it will always give us the vertex with the smallest distance
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    for (int hospital_node : hospital_locations) {
        dist[hospital_node] = 0; // Distance from hospitals to themselves is 0
        pq.push({0, hospital_node}); // Push all hospital nodes into the priority queue
    }
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If we've found a shorter path to 'u' already, skip this entry
        // (this can happen because we might push multiple paths to 'u' into the PQ)
        if (d > dist[u]) {
            continue;
        }

        // Iterate over all neighbors 'v' of 'u'
        for (auto &edge : g[u]) {
            int v = edge.first;
            int weight = edge.second;

            // If a shorter path to 'v' is found through 'u'
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m; // n: number of vertices, m: number of edges
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        g[u].push_back({v, wt});
        // For undirected graph, add edge in both directions
        // If directed, remove the line below
        g[v].push_back({u, wt});
    }

    cout << "Enter the number of hospital locations: ";
    int num_hospitals;
    cin >> num_hospitals;

    vector<int> hospital_locations(num_hospitals);
    cout << "Enter the " << num_hospitals << " hospital locations: ";
    for (int i = 0; i < num_hospitals; ++i) {
        cin >> hospital_locations[i];
    }

    dijkstra(hospital_locations, n);

    cout << "\nShortest distances to any hospital from each node:\n";
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) {
            cout << "From node " << i << ": Unreachable\n";
        } else {
            cout << "From node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
