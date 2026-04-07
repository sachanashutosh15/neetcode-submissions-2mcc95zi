/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> store;
        function<Node*(Node*)> dfs = [&](Node* curr) -> Node* {
            if (store.count(curr)) return store[curr];
            Node* copy = new Node(curr->val);
            store[curr] = copy;
            for (auto& nbr: curr->neighbors) {
                copy->neighbors.push_back(dfs(nbr));
            }
            return copy;
        };
        return dfs(node);
    }
};
