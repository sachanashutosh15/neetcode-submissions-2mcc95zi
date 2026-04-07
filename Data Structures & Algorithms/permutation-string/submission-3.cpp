class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m1(26, 0), m2(26, 0);
        int m = s1.size(), n = s2.size();
        if (m > n) return false;
        for (int i = 0; i < m; i++) {
            m1[s1[i] - 'a']++;
            m2[s2[i] - 'a']++;
        }
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (m1[i] == m2[i]) matches++;
        }
        for (int i = m; i < n; i++) {
            if (matches == 26) return true;
            char incoming = s2[i] - 'a';
            char outgoing = s2[i - m] - 'a';

            if (m1[incoming] == m2[incoming]) matches--;
            m2[incoming]++;
            if (m1[incoming] == m2[incoming]) matches++;

            if (m1[outgoing] == m2[outgoing]) matches--;
            m2[outgoing]--;
            if (m1[outgoing] == m2[outgoing]) matches++;
        }
        
        return matches == 26;
    }
};
