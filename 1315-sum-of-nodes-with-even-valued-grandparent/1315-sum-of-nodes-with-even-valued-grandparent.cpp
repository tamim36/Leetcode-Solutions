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
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*> q;
    q.push(root);
    int sum = 0;

    while (!q.empty())
    {
        TreeNode* cur = q.front(); q.pop();
        if (!(cur->val % 2)) {
            sum += cur->left ? cur->left->left ? cur->left->left->val : 0 : 0;
            sum += cur->left ? cur->left->right ? cur->left->right->val : 0 : 0;
            sum += cur->right ? cur->right->left ? cur->right->left->val : 0 : 0;
            sum += cur->right ? cur->right->right ? cur->right->right->val : 0 : 0;
        }

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    return sum;
    }
};