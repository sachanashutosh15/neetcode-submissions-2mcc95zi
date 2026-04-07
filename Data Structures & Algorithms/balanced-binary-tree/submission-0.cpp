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
    int height(TreeNode* root, int& maxHeightDiff) {
        if (!root) return 0;
        int leftH = height(root->left, maxHeightDiff);
        int rightH = height(root->right, maxHeightDiff);
        maxHeightDiff = max(maxHeightDiff, abs(leftH - rightH));
        return 1 + max(leftH, rightH);
    }
public:
    bool isBalanced(TreeNode* root) {
        int maxHeightDiff = 0;
        height(root, maxHeightDiff);
        if (maxHeightDiff > 1) return false;
        return true;
    }
};
