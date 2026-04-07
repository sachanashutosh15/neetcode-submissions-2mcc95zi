class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1) return s;
        int resIdx = 0, len = 1;
        vector<vector<int>> memo(n, vector<int>(n, -1));
        function<bool(int, int)> isPalindrome = [&](int i, int j) -> bool {
            if (i >= j) return true;
            if (s[i] != s[j]) return false;
            if (memo[i][j] != -1) return memo[i][j];
            return memo[i][j] = isPalindrome(i + 1, j - 1);
        };
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (i < j && isPalindrome(i, j) && j - i + 1 > len) {
                    resIdx = i;
                    len = j - i + 1;
                }
            }
        }
        return s.substr(resIdx, len);
    }
};
