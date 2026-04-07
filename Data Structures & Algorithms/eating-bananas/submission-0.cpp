class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1, end = *max_element(piles.begin(), piles.end());
        function<bool(int)> isPossible = [&](int eatingRate) -> bool {
            int time = 0;
            for (int cnt: piles) {
                time += (cnt + eatingRate - 1) / eatingRate;
            }
            return time <= h;
        };
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isPossible(mid)) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return end + 1;
    }
};
