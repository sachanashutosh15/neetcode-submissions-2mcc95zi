class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), minDiffSum = INT_MAX, start = -1, diffSum = 0;
        for (int i = 0; i < n; i++) {
            diffSum += gas[i] - cost[i];
            if (diffSum < minDiffSum) {
                minDiffSum = diffSum;
                start = (i + 1) % n;
            }
        }
        return diffSum < 0 ? -1 : start;
    }
};
