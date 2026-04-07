class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        function<void(int)> solve = [&](int idx) -> void {
            if (idx == nums.size()) {
                res.push_back(nums);
                return;
            }
            for (int i = idx; i < nums.size(); i++) {
                swap(nums[i], nums[idx]);
                solve(idx + 1);
                swap(nums[i], nums[idx]);
            }
        };
        solve(0);
        return res;
    }
};
