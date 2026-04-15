class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthestJump = 0;
        for (int i = 0; i < n; i++) {
            if (farthestJump < i) {
                return false;
            }
            farthestJump = max(farthestJump, i + nums[i]);
        }
        return true;
    }
};
