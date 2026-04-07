class Solution {
    vector<int> memo;

    int solve(int i) {
        if (i == 0) return 1;
        if (i == 1) return 1;
        if (memo[i] != -1) return memo[i];
        return memo[i] = solve(i - 1) + solve(i - 2);
    }
public:
    int climbStairs(int n) {
        memo.resize(n + 1, -1);
        return solve(n);
    }
};
