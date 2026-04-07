class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n = nums1.size() + nums2.size();
        int half = (n + 1) / 2;
        int l = 0, r = nums1.size();
        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = half - i;
            int aLeft = i - 1 >= 0 ? nums1[i - 1] : INT_MIN;
            int aRight = i < nums1.size() ? nums1[i] : INT_MAX;
            int bLeft = j - 1 >= 0 ? nums2[j - 1] : INT_MIN;
            int bRight = j < nums2.size() ? nums2[j] : INT_MAX;
            if (aLeft <= bRight && bLeft <= aRight) {
                if (n % 2 == 1) {
                    return max(aLeft, bLeft);
                }
                return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
            } else if (aLeft > bRight) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return -1;
    }
};
