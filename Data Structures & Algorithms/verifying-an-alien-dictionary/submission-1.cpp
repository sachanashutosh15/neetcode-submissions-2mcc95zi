class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> charIdxMp;
        for (int i = 0; i < 26; i++) {
            charIdxMp[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            for (int j = 0; j < w1.size(); j++) {
                if (j == w2.size() || charIdxMp[w1[j]] > charIdxMp[w2[j]]) {
                    return false;
                }
                if (charIdxMp[w1[j]] < charIdxMp[w2[j]]) {
                    break;
                }
            }
        }
        return true;
    }
};