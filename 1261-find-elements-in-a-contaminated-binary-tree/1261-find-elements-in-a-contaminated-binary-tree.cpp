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
class FindElements {
private:
    unordered_set<int> values;
    void recoverTree(TreeNode* root) {
        if (!root) return;

        if (root->val == -1) root->val = 0;

        values.insert(root->val);

        if (root->left) root->left->val = (root->val * 2) + 1;
        if (root->right) root->right->val = (root->val * 2) + 2;

        recoverTree(root->left);
        recoverTree(root->right);
    }

public:
    FindElements(TreeNode* root) {
        recoverTree(root);
    }

    bool find(int target) {
        return values.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */