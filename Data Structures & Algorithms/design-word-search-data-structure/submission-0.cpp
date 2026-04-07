class WordDictionary {
    vector<WordDictionary*> children;
    bool isEnd;

    bool dfs(string& word, WordDictionary* node, int idx) {
        if (!node) return false;
        if (idx == word.size()) return node->isEnd;
        if (word[idx] == '.') {
            for (auto& child: node->children) {
                if (dfs(word, child, idx + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            return dfs(word, node->children[word[idx] - 'a'], idx + 1);
        }
    }
public:
    WordDictionary() {
        children.resize(26, nullptr);
        isEnd = false;
    }
    
    void addWord(string word) {
        WordDictionary* node = this;
        for (char& c: word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new WordDictionary();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, this, 0);
    }
};
