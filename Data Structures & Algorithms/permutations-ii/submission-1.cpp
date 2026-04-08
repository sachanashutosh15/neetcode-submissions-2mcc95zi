class Solution {
    void solve(int i, vector<int>& nums, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for (int j = i; j < nums.size(); j++) {
            if (used.count(nums[j])) continue;
            used.insert(nums[j]);
            swap(nums[i], nums[j]);
            solve(i + 1, nums, res);
            swap(nums[i], nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        solve(0, nums, res);
        return res;
    }
};