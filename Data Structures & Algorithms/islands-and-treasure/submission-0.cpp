class Solution {
    vector<int> dirs = {-1, 0, 1, 0, -1};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const long INF = 2147483647;
        function<void(int, int)> bfs = [&](int i, int j) -> void {
            queue<tuple<int, int, int>> q;
            q.push({i, j, 0});
            vector<vector<bool>> vis(m, vector<bool>(n, false));
            vis[i][j] = true;
            while (!q.empty()) {
                auto [i, j, dist] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int ni = i + dirs[k], nj = j + dirs[k + 1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (grid[ni][nj] != 0 && grid[ni][nj] != -1 && !vis[ni][nj]) {
                        grid[ni][nj] = min(grid[ni][nj], dist + 1);
                        vis[ni][nj] = true;
                        q.emplace(ni, nj, dist + 1);
                    }
                }
            }
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    bfs(i, j);
                }
            }
        }
    }
};
