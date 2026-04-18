class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            int currGas = 0, j = 0;
            while (j < n) {
                int currIdx = (i + j) % n;
                currGas += gas[currIdx];
                if (currGas < cost[currIdx]) break;
                currGas -= cost[currIdx];
                if (j == n - 1) return i;
                j++;
            }
        }
        return -1;
    }
};
