class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -2));
        function<int(int, int)> solve = [&](int idx, int rem) -> int {
            if (idx == coins.size() || rem < 0) return -1;
            if (memo[idx][rem] != -2) return memo[idx][rem];
            if (rem == 0) return 0;
            int res = INT_MAX;
            int pick = solve(idx, rem - coins[idx]);
            int skip = solve(idx + 1, rem);
            if (pick != -1) {
                res = min(1 + pick, res);
            }
            if (skip != -1) {
                res = min(skip, res);
            }
            return memo[idx][rem] = (res == INT_MAX ? -1 : res);
        };
        return solve(0, amount);
    }
};
