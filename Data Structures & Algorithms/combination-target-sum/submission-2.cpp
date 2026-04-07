class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> set;
        sort(nums.begin(), nums.end());
        function<void(int, int)> solve = [&](int idx, int rem) ->void {
            if (rem == 0) {
                res.push_back(set);
                return;
            }
            if (rem < 0) {
                return;
            }
            for (int i = idx; i < nums.size(); i++) {
                set.push_back(nums[i]);
                solve(i, rem - nums[i]);
                set.pop_back();
            }
        };
        solve(0, target);
        return res;
    }
};
