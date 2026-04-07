class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int n = strs.size();
        int m = INT_MAX;
        for (auto str: strs) {
            if (str.size() < m) {
                m = str.size();
            }
        }
        for (int i = 0; i < m; i++) {
            char c = strs[0][i];
            for (int j = 1; j < n; j++) {
                if (strs[j][i] != c) {
                    return res;
                }
            }
            res += c;
        }
        return res;
    }
};