class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int preProd = 0, suffProd = 0;
        int res = nums[0], n = nums.size();
        for (int i = 0; i < n; i++) {
            preProd = nums[i] * (preProd == 0 ? 1 : preProd);
            suffProd = nums[n - 1 - i] * (suffProd == 0 ? 1 : suffProd);
            res = max(res, max(preProd, suffProd));
        }
        return res;
    }
};
