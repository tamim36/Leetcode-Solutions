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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root || !root->left || !root->right)
            return root;

        vector<TreeNode*> vec;
        vec.push_back(root);
        bool isOdd = false;
        while (!vec.empty()) {
            int sz = vec.size();
            if (isOdd) {
                for (int i = 0, j = sz - 1; i < sz / 2; i++, j--) {
                    TreeNode *first = vec[i], *sec = vec[j];
                    int tempVal = sec->val;
                    sec->val = first->val;
                    first->val = tempVal;
                }
            }

            vector<TreeNode*> temp;
            if (vec[0]->left) {
                for (int i = 0; i < sz; i++) {
                    temp.push_back(vec[i]->left);
                    temp.push_back(vec[i]->right);
                }
            }

            vec.clear();
            vec = temp;
            isOdd = !isOdd;
        }

        return root;
    }
};