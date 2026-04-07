class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> nextGreatestEle(n);
        vector<int> prevGreatestEle(n);
        int next = 0, prev = 0;
        for (int i = 0; i < n; i++) {
            nextGreatestEle[n - 1 - i] = next;
            prevGreatestEle[i] = prev;
            next = max(next, height[n - 1 - i]);
            prev = max(prev, height[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int currWater = min(nextGreatestEle[i], prevGreatestEle[i]) - height[i];
            if (currWater > 0) res += currWater;
        }
        return res;
    }
};
