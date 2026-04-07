class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        function<void(int, int)> solve = [&](int idx, int rem) -> void {
            if (rem == 0) {
                res.push_back(curr);
                return;
            }
            for (int i = idx; i < candidates.size(); i++) {
                if (i > idx && candidates[i - 1] == candidates[i]) continue;
                if (candidates[i] > rem) {
                    break;
                }
                curr.push_back(candidates[i]);
                solve(i + 1, rem - candidates[i]);
                curr.pop_back();
            }
        };
        solve(0, target);
        return res;
    }
};
