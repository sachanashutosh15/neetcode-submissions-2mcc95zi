class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, false);
        function<bool(int, int)> hasCycle = [&](int i, int p) -> bool {
            vis[i] = true;
            for (auto& nei: adj[i]) {
                if (!vis[nei]) {
                    if (hasCycle(nei, i)) return true;
                } else if (nei != p) {
                    return true;
                }
            }
            return false;
        };
        if(hasCycle(0, -1)) return false;
        for (bool v: vis) {
            if (!v) return false;
        }
        return true;
    }
};
