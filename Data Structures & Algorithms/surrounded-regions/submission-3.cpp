class Solution {
    vector<int> dirs = {-1, 0, 1, 0, -1};
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        function<bool(int, int)> isSurrounded = [&](int i, int j) -> bool {
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1) return false;
            vis[i][j] = true;
            for (int k = 0; k < 4; k++) {
                int ni = i + dirs[k], nj = j + dirs[k + 1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (!vis[ni][nj] && board[ni][nj] == 'O') {
                    cout << ni << ' ' << nj << '\n';
                    if (!isSurrounded(ni, nj)) {
                        return false;
                    }
                }
            }
            return true;
        };
        function<void(int, int)> capture = [&](int i, int j) -> void {
            board[i][j] = 'X';
            for (int k = 0; k < 4; k++) {
                int ni = i + dirs[k], nj = j + dirs[k + 1];
                if (board[ni][nj] == 'O') {
                    capture(ni, nj);
                }
            }
        };
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    vis.assign(m, vector<bool>(n, false));
                    if (isSurrounded(i, j)) {
                        capture(i, j);
                    }
                }
            }
        }
    }
};
