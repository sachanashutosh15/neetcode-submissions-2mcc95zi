class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freqMap;
            int maxFreq = 0;
            for (int j = i; j < n; j++) {
                freqMap[s[j]]++;
                maxFreq = max(maxFreq, freqMap[s[j]]);
                if (j - i + 1 - maxFreq <= k) {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};
