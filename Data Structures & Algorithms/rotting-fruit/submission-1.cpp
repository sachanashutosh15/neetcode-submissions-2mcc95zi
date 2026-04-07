class Solution {
    vector<int> dirs = {-1, 0, 1, 0, -1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                    vis[i][j] = true;
                }
            }
        }
        int t = -1;
        while (!q.empty()) {
            t++;
            int s = q.size();
            cout << s << '\n';
            for (int si = 0; si < s; si++) {
                auto [i, j] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int ni = i + dirs[k], nj = j + dirs[k + 1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    if (!vis[ni][nj] && grid[ni][nj] != 0) {
                        q.emplace(ni, nj);
                        grid[ni][nj] = 2;
                        vis[ni][nj] = true;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return t == -1 ? 0 : t;
    }
};
