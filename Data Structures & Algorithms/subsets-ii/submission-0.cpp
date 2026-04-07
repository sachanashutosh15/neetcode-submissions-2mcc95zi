class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        function<void(int)> solve = [&](int idx) -> void {
            res.push_back(curr);
            for (int i = idx; i < nums.size(); i++) {
                if (i > idx && nums[i - 1] == nums[i]) continue;
                curr.push_back(nums[i]);
                solve(i + 1);
                curr.pop_back();
            }
        };
        solve(0);
        return res;
    }
};
