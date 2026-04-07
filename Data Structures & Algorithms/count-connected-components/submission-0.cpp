class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res = 0;
        vector<bool> vis(n, false);
        function<void(int)> dfs = [&](int i) -> void {
            vis[i] = true;
            for (auto& nei: adj[i]) {
                if (!vis[nei]) {
                    dfs(nei);
                }
            }
        };
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                res++;
                dfs(i);
            }
        }
        return res;
    }
};
