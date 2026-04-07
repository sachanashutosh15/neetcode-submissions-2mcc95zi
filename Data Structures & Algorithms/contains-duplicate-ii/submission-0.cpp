class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int j = 0, n = nums.size();
        set<int> window;
        for (int i = 0; i < n; i++) {
            if (i - j > k) {
                window.erase(nums[j++]);
            }
            if (window.count(nums[i])) {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};