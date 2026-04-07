class Solution {
    vector<int> dirs = {-1, 0, 1, 0, -1};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            vis[i][j] = true;
            int area = 1;
            for (int k = 0; k < 4; k++) {
                int ni = i + dirs[k], nj = j + dirs[k + 1];
                if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size()) continue;
                if (grid[ni][nj] == 1 && !vis[ni][nj]) {
                    area += dfs(ni, nj);
                }
            }
            return area;
        };
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    maxArea = max(maxArea, dfs(i, j));
                }
            }
        }
        return maxArea;
    }
};
