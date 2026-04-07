class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> memo(n, -1);
        function<int(int)> decode = [&](int idx) -> int {
            if (idx == n) return 1;
            if (s[idx] == '0' || idx > n) return 0;
            if (memo[idx] != -1) return memo[idx];
            if ((s[idx] - '0' == 2 && idx < n - 1 && s[idx + 1] - '0' > 6) || s[idx] - '0' > 2) {
                return memo[idx] = decode(idx + 1);
            } else {
                return memo[idx] = decode(idx + 1) + decode(idx + 2);
            }
        };
        return decode(0);
    }
};
