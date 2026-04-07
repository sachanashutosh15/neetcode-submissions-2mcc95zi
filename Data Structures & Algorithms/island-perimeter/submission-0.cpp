class Solution {
    vector<int> dirs = {-1, 0, 1, 0, -1};
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        int res = 0;
        for (int k = 0; k < 4; k++) {
            int ni = i + dirs[k], nj = j + dirs[k + 1];
            if (ni < 0 || ni == grid.size() || nj < 0 || nj == grid[0].size() || grid[ni][nj] == 0) {
                res += 1;
                continue;
            }
            if (grid[ni][nj] && !vis[ni][nj]) {
                res += dfs(ni, nj, grid, vis);
            }
        }
        return res;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    return dfs(i, j, grid, vis);
                }
            }
        }
        return -1;
    }
};