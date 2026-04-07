class Solution {
    vector<int> memo;

    int minCost(int i, vector<int> &cost) {
        if (i == 0 || i == 1) return cost[i];
        if (memo[i] != -1) return memo[i];
        return memo[i] = cost[i] + min(minCost(i - 1, cost), minCost(i - 2, cost));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memo.resize(n, -1);
        return min(minCost(n - 1, cost), minCost(n - 2, cost));
    }
};
