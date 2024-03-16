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
class BSTIterator {
private:
    queue<int> q;

    void recursiveInorder(TreeNode* root) {
        if (!root) return;

        recursiveInorder(root->left);
        q.push(root->val);
        recursiveInorder(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        recursiveInorder(root);
    }

    int next() {
        int val = q.front();
        q.pop();
        return val;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */