class Solution {
public:
    void dfs(int x, int y, int n, int m, vector<vector<char>>& grid){
        // Base cases for recursion:
        // 1. Out of bounds
        // 2. Already visited (water '0' or part of another island we've sunk)
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '0') {
            return;
        }

        // Mark the current land cell as visited by changing it to '0' (water)
        grid[x][y] = '0';

        // Explore in 4 directions (horizontally and vertically)
        dfs(x + 1, y, n, m, grid); // Down
        dfs(x - 1, y, n, m, grid); // Up
        dfs(x, y + 1, n, m, grid); // Right
        dfs(x, y - 1, n, m, grid); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int n = grid.size();
        int m = grid[0].size();

        int island = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    island++;
                    dfs(i, j, n, m, grid);
                }
            }
        }
        return island;
    }
};
