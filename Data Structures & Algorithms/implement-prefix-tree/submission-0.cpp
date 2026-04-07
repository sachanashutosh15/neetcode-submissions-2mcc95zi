class PrefixTree {
    vector<PrefixTree*> children;
    bool isEnd; 
public:
    PrefixTree() {
        children.resize(26, nullptr);
        isEnd = false;
    }
    
    void insert(string word) {
        auto node = this;
        for (char& c: word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new PrefixTree();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        auto node = this;
        for (char& c: word) {
            if (!node->children[c - 'a']) {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return node && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        auto node = this;
        for (char& c: prefix) {
            if (!node->children[c - 'a']) {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return true;
    }
};
