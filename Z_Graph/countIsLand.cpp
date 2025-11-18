#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<int>> vis;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
    vis[x][y] = 1;

    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if(!vis[nx][ny] && grid[nx][ny] == 'L') {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    grid.resize(n);
    vis.assign(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int islands = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'L' && !vis[i][j]) {
                islands++;
                dfs(i, j);
            }
        }
    }

    cout << islands << "\n";
    return 0;
}
