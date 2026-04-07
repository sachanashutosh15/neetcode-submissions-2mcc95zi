class Solution {
    bool isAdj(string a, string b) {
        int dist = 0, n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                dist++;
                if (dist == 2) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string, vector<string>> adj;
        int n = wordList.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isAdj(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        queue<string> q;
        q.push(beginWord);
        set<string> visited;
        visited.insert(beginWord);
        int res = 0;
        while (!q.empty()) {
            int s = q.size();
            res++;
            for (int i = 0; i < s; i++) {
                string currStr = q.front(); q.pop();
                if (currStr == endWord) return res;
                for (auto& word: adj[currStr]) {
                    if (!visited.count(word)) {
                        q.push(word);
                        visited.insert(word);
                    }
                }
            }
        }
        return 0;
    }
};
