class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0, twenties = 0;
        int n = bills.size();
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                fives++;
            } else if (bills[i] == 10) {
                if (fives < 1) {
                    return false;
                }
                fives--;
                tens++;
            } else if (bills[i] == 20) {
                if (fives >= 3) {
                    fives -= 3;
                    twenties++;
                } else if (fives >= 1 && tens >= 1) {
                    fives -= 1;
                    tens -= 1;
                    twenties++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};