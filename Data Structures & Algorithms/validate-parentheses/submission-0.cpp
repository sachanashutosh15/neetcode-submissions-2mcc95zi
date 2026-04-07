class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        unordered_map<char, char> pairs = {
            {'{', '}'},
            {'(', ')'},
            {'[', ']'}
        };
        for (int i = 0; i < n; i++) {
            if (!st.empty() && pairs[st.top()] == s[i]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
            cout << st.size() << '\n';
        }
        return st.empty();
    }
};
