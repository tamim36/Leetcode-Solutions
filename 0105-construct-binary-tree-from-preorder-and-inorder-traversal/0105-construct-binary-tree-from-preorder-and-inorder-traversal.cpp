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
    unordered_set<int> visTree;
TreeNode* dfsToBuildTree(int preStart, int inStart, int inEnd, vector<int>& pre, vector<int>& in) {
    if (inStart >= inEnd || preStart >= pre.size())
        return NULL;

    while (visTree.count(pre[preStart]))
    {
        preStart++;
    }
    TreeNode* root = new TreeNode(pre[preStart]);
    visTree.insert(pre[preStart]);
    if (inEnd - inStart == 1)
        return root;
    int idx = 0;
    for (idx = inStart; idx < inEnd; idx++) {
        if (pre[preStart] == in[idx])
            break;
    }
    preStart++;
    root->left = dfsToBuildTree(preStart, inStart, idx, pre, in);
    if (!root->left) preStart--;
    root->right = dfsToBuildTree(preStart+1, idx+1, inEnd, pre, in);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return dfsToBuildTree(0, 0, inorder.size(), preorder, inorder);
}

};