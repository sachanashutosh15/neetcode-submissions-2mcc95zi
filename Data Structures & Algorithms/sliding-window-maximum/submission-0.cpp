class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size(), l = 0;
        vector<int> res(n - k + 1);
        for (int r = 0; r < n; r++) {
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);
            if (dq.front() < l) {
                dq.pop_front();
            }
            if (r >= k - 1) {
                res[l] = nums[dq.front()];
                l++;
            }
        }
        return res;
    }
};
