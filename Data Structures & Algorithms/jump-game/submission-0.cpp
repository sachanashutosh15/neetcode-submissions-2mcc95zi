class Solution {
public:
    bool canJump(vector<int>& nums, int idx = 0) {
        if (idx == nums.size() - 1) return true;
        for (int i = 1; i <= nums[idx]; i++) {
            if (canJump(nums, i + idx)) return true;
        }
        return false;
    }
};
