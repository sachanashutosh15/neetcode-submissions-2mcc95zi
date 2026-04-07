class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if (sum > 1) {
                vis[i] = vector<bool>(n, true);
                res += sum;
            }
        }
        for (int j = 0; j < n; j++) {
            int sum = 0;
            int visSum = 0;
            for (int i = 0; i < m; i++) {
                sum += grid[i][j];
                if (grid[i][j] && vis[i][j]) {
                    visSum++;
                }
            }
            if (sum > 1) res += (sum - visSum);
        }
        return res;
    }
};