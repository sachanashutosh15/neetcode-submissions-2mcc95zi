class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = 1, currMin = 1, n = nums.size();
        int res = nums[0];
        for (auto num: nums) {
            int tmp = currMax * num;
            currMax = max(max(tmp, currMin * num), num);
            currMin = min(min(tmp, currMin * num), num);
            res = max(res, currMax);
        }
        return res;
    }
};
