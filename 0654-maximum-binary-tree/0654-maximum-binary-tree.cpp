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
    TreeNode* dfsconstructMaximumBinaryTree(vector<int>& nums, int st, int end) {
    if (st > end || st >= nums.size() || end < 0)
        return NULL;
    int indx = st;
    for (int i = st; i <= end; i++) {
        if (nums[i] > nums[indx])
            indx = i;
    }

    TreeNode* root = new TreeNode(nums[indx]);
    root->left = dfsconstructMaximumBinaryTree(nums, st, indx-1);
    root->right = dfsconstructMaximumBinaryTree(nums, indx+1, end);
    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return dfsconstructMaximumBinaryTree(nums, 0, nums.size()-1);
}
};