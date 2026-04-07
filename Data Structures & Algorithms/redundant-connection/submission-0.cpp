class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ranks(n + 1, 1), parents(n + 1);
        for (int i = 0; i <= n; i++) {
            parents[i] = i;
        }
        for (auto& edge: edges) {
            if (!Union(parents, ranks, edge[0], edge[1])) {
                return {edge[0], edge[1]};
            }
        }
        return {};
    }

    int find(vector<int>& parents, int n) {
        int p = parents[n];
        while (p != parents[p]) {
            parents[p] = parents[parents[p]];
            p = parents[p];
        }
        return p;
    }

    bool Union(vector<int>& parents, vector<int>& ranks, int n1, int n2) {
        int p1 = find(parents, n1);
        int p2 = find(parents, n2);
        if (p1 == p2) return false;
        if (ranks[p1] < ranks[p2]) swap(p1, p2);
        ranks[p1] += ranks[p2];
        parents[p2] = p1;
        return true;
    }
};
