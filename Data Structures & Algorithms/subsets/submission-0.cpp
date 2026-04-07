class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> set;
        function<void(int)> createSubsets = [&](int idx) -> void {
            if (idx == nums.size()) {
                res.push_back(set);
                return;
            }
            res.push_back(set);
            for (int i = idx; i < nums.size(); i++) {
                set.push_back(nums[i]);
                createSubsets(i + 1);
                set.pop_back();
            }
        };
        createSubsets(0);
        return res;
    }
};
