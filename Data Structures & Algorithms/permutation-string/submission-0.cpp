class Solution {
public:
    bool matchMaps(unordered_map<char, int>& m1, unordered_map<char, int>& m2) {
        for (auto [c, cnt]: m1) {
            if (m2[c] != cnt) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int m = s1.size(), n = s2.size();
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for (int i = 0; i < m; i++) {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        if (matchMaps(m1, m2)) return true;
        for (int i = m; i < n; i++) {
            m2[s2[i]]++;
            m2[s2[i - m]]--;
            if (m2[s2[i - m]] == 0) {
                m2.erase(s2[i - m]);
            }
            if (matchMaps(m1, m2)) return true;
        }
        return false;
    }
};
