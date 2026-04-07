class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> prevSmallerIdx(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                prevSmallerIdx[i] = -1;
            } else {
                prevSmallerIdx[i] = st.top();
            }
            st.push(i);
        }
        st = stack<int>();
        vector<int> nextSmallerIdx(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                nextSmallerIdx[i] = n;
            } else {
                nextSmallerIdx[i] = st.top();
            }
            st.push(i);
        }
        int maxRect = 0;
        for (int i = 0; i < n; i++) {
            maxRect = max(maxRect, heights[i] * (nextSmallerIdx[i] - prevSmallerIdx[i] - 1));
        }
        return maxRect;
    }
};
