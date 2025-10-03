/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int getTotalOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        return root->val + getTotalOfBinaryTree(root->left) +
               getTotalOfBinaryTree(root->right);
    }

    long long global_cur_maxProduct = 1;
    long long helper_maxProduct(TreeNode* root, int total) {
        if (!root)
            return 0;

        long long cur_sum = root->val + helper_maxProduct(root->left, total) +
                            helper_maxProduct(root->right, total);
        global_cur_maxProduct =
            max(global_cur_maxProduct, cur_sum * ((total * 1ll) - cur_sum));

        return cur_sum;
    }

    int maxProduct(TreeNode* root) {
        int total = getTotalOfBinaryTree(root);
        cout << total << endl;

        helper_maxProduct(root, total);
        int ans = (global_cur_maxProduct % 1000000007);
        return ans;
    }
};