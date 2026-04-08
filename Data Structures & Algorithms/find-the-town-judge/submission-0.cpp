class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, unordered_set<int>> adj;
        for (auto& t: trust) {
            adj[t[0]].insert(t[1]);
        }
        int judge = -1;
        for (int i = 1; i <= n; i++) {
            if (!adj.count(i)) {
                judge = i;
                break;
            }
        }
        if (judge == -1) return -1;
        for (auto& [_, grp]: adj) {
            if (!grp.count(judge)) {
                return -1;
            }
        }
        return judge;
    }
};