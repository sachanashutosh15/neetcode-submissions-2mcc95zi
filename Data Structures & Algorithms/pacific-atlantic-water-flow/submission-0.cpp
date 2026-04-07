class Solution {
    vector<int> dirs = {-1, 0, 1, 0, -1};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        function<void(int, int, pair<bool, bool>&)> dfs = [&](int i, int j, pair<bool, bool>& flowPA) -> void {
            if (i == 0 || j == 0) flowPA.first = true;
            if (i == m - 1 || j == n - 1) flowPA.second = true;
            vis[i][j] = true;
            for (int k = 0; k < 4; k++) {
                int ni = i + dirs[k], nj = j + dirs[k + 1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (!vis[ni][nj] && heights[i][j] >= heights[ni][nj]) {
                    dfs(ni, nj, flowPA);
                }
            }
        };
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pair<bool, bool> flowPA = {false, false};
                vis.assign(m, vector<bool>(n, false));
                dfs(i, j, flowPA);
                if (flowPA.first && flowPA.second) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
