class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxInFuture = 0, n = prices.size();
        int maxProfit = 0;
        for (int i = n - 1; i >= 0; i--) {
            maxProfit = max(maxProfit, maxInFuture - prices[i]);
            maxInFuture = max(maxInFuture, prices[i]);
        }
        return maxProfit;
    }
};
