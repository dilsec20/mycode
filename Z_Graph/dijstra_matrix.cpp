#include <bits/stdc++.h>
using namespace std;

int dijkstraGrid(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    // Min-heap: {cost, x, y}
    priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq;

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], 0, 0});

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        int cost = t[0];
        int x = t[1];
        int y = t[2];

        if(cost != dist[x][y]) continue; // stale

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {

                int newCost = cost + grid[nx][ny];

                if(newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, nx, ny});
                }
            }
        }
    }

    return dist[n-1][m-1];  // Shortest path to bottom-right
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    cout << dijkstraGrid(grid) << "\n";
    return 0;
}
