class Solution {
    vector<vector<int>> memo;
    bool solve(string s, set<string>& dict, int i, int j) {
        if (j == s.size()) {
            if (i == j) return true;
            return false;
        }
        if (memo[i][j] != -1) return memo[i][j];
        if (dict.count(s.substr(i, j - i + 1))) {
            return memo[i][j] = solve(s, dict, i, j + 1) || solve(s, dict, j + 1, j + 1);
        } else {
            return memo[i][j] = solve(s, dict, i, j + 1);
        }
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        for (auto word: wordDict) {
            dict.insert(word);
        }
        int n = s.size();
        memo.resize(n + 1, vector<int>(n + 1, -1));
        return solve(s, dict, 0, 0);
    }
};
