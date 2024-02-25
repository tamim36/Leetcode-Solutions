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
    int value_to_bstToGst = 0;
TreeNode* bstToGst(TreeNode* root) {
    if (!root)
        return root;

    bstToGst(root->right);
    value_to_bstToGst += root->val;
    root->val = value_to_bstToGst;
    bstToGst(root->left);

    return root;
}
};