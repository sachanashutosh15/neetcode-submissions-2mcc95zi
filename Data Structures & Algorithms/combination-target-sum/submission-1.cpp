class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> set;
        function<void(int, int)> solve = [&](int idx, int rem) -> void {
            if (rem == 0) {
                res.push_back(set);
                return;
            }
            if (rem < 0 || idx >= nums.size()) {
                return;
            }
            set.push_back(nums[idx]);
            solve(idx, rem - nums[idx]);
            set.pop_back();
            solve(idx + 1, rem);
        };
        solve(0, target);
        return res;
    }
};
