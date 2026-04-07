class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto pre: prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }
        unordered_set<int> taken;
        function<bool(int)> canTake = [&](int crs) -> bool {
            if (adj[crs].empty()) return true;
            if (taken.count(crs)) return false;
            taken.insert(crs);
            for (auto pre: adj[crs]) {
                if (!canTake(pre)) {
                    return false;
                }
            }
            taken.erase(crs);
            adj[crs].clear();
            return true;
        };
        for (int i = 0; i < numCourses; i++) {
            if (!canTake(i)) {
                return false;
            }
        }
        return true;
    }
};
