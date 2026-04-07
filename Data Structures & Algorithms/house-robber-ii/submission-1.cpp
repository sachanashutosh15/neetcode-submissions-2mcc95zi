class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<vector<int>> memo(2, vector<int>(n, -1));
        function<int(int, int)> solve = [&](int i, int j) -> int {
            if (i >= j) return 0;
            if (memo[n - j][i] != -1) return memo[n - j][i];
            return memo[n - j][i] = max(nums[i] + solve(i + 2, j), solve(i + 1, j));
        };
        return max(solve(0, n - 1), solve(1, n));
    }
};
