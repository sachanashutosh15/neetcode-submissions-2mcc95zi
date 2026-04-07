/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int maxHeight(TreeNode* root, int& res) {
        if (!root) return 0;
        int lMaxH = maxHeight(root->left, res);
        int rMaxH = maxHeight(root->right, res);
        res = max(res, lMaxH + rMaxH);
        return 1 + max(lMaxH, rMaxH);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        maxHeight(root, res);
        return res;
    }
};
