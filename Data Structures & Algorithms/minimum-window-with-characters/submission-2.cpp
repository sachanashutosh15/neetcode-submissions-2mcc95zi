class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> required, window;
        for (char ch: t) required[ch]++;
        int n = s.size(), matches = 0, l = 0;
        string res = "";
        for (int r = 0; r < n; r++) {
            if (required.count(s[r])) {
                window[s[r]]++;
                if (required[s[r]] == window[s[r]]) matches++;
            }
            while (matches == required.size()) {
                if (res == "" || r - l + 1 < res.size()) {
                    res = s.substr(l, r - l + 1);
                }
                if (required.count(s[l])) {
                    window[s[l]]--;
                    if (required[s[l]] > window[s[l]]) matches--;
                }
                l++;
            }
        }
        return res;
    }
};
