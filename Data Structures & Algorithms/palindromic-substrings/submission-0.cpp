class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        vector<vector<int>> memo(n, vector<int>(n, -1));
        function<bool(int, int)> isPalindrome = [&](int i, int j) -> bool {
            if (i >= j) return true;
            if (s[i] != s[j]) return false;
            if (memo[i][j] != -1) return memo[i][j];
            return memo[i][j] = isPalindrome(i + 1, j - 1);
        };
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (i <= j) {
                    if (isPalindrome(i, j)) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
