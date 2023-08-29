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
    TreeNode* prevNode = new TreeNode(INT_MIN);
TreeNode* firstNode = NULL;
TreeNode* secNode = NULL;
TreeNode* lastNode = NULL;

void SwapNodeVal(TreeNode* node1, TreeNode* node2) {
    if (!node1 || !node2) {
        return;
    }

    int temp = node1->val;
    node1->val = node2->val;
    node2->val = temp;
}

void recoverTreeInOrder(TreeNode* root) {
    if (!root) return;
    recoverTreeInOrder(root->left);

    if (firstNode == NULL && prevNode && prevNode->val > root->val) {
        firstNode = prevNode;
        secNode = root;
    }
    else if (firstNode && prevNode->val > root->val)
        secNode = root;

    prevNode = root;
    recoverTreeInOrder(root->right);
}

void recoverTree(TreeNode* root) {
    if (!root) return;
    recoverTreeInOrder(root);

    if (!secNode)
        secNode = prevNode;

    SwapNodeVal(firstNode, secNode);
}
};