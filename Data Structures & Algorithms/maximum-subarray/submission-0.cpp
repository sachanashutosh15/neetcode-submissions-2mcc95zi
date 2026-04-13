class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            res = max(res, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return res;
    }
};
