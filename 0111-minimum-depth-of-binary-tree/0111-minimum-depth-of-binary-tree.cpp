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
public:
    int minDepth(TreeNode* root) {
        if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    left = left == 0 ? INT_MAX : left;
    right = right == 0 ? INT_MAX : right;

    return 1 + min(left, right);
    }
};