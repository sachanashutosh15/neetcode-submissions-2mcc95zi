class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int st = 0, end = m - 1;
        while (st < end) {
            int mid = st + (end - st) / 2;
            if (matrix[mid][n - 1] < target) {
                st = mid + 1;
            } else {
                end = mid;
            }
        }
        int rowIdx = st;
        st = 0; end = n - 1;
        while (st < end) {
            int mid = st + (end - st) / 2;
            if (matrix[rowIdx][mid] < target) {
                st = mid + 1;
            } else {
                end = mid;
            }
        }
        return matrix[rowIdx][st] == target;
    }
};
