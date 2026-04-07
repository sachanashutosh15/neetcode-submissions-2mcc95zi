class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIdxMp;
        int n = s.size(), l = 0, res = 0;
        for (int i = 0; i < n; i++) {
            while (charIdxMp.count(s[i])) {
                charIdxMp.erase(s[l++]);
            }
            charIdxMp[s[i]] = i;
            res = max(res, i - l + 1);
        }
        return res;
    }
};
