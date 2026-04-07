class Solution {
    vector<int> dirs = {-1, 0, 1, 0, -1};
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        function<void(int, int)> dfs = [&](int i, int j) -> void {
            vis[i][j] = true;
            for (int k = 0; k < 4; k++) {
                int ni = i + dirs[k], nj = j + dirs[k + 1];
                if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size()) continue;
                if (grid[ni][nj] == '1' && !vis[ni][nj]) {
                    dfs(ni, nj);
                }
            }
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    res++;
                    dfs(i, j);
                }
            }
        }
        return res;
    }
};
