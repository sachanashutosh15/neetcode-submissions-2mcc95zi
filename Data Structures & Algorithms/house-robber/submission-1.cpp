class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        function<int(int)> maxAmt = [&](int i) -> int {
            if (i < 0) return 0;
            if (i == 0) return nums[0];
            if (dp[i] != -1) return dp[i];
            return dp[i] = max(nums[i] + maxAmt(i - 2), maxAmt(i - 1));
        };

        return maxAmt(n - 1);
    }
};
