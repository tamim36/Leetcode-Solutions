class Solution {
public:
    int minInc = 0;
int dfsToMinIncrements(TreeNode* root) {
    if (!root) return 0;

    int cur = root->val;
    int l = cur + dfsToMinIncrements(root->left);
    int r = cur + dfsToMinIncrements(root->right);

    minInc += abs(l - r);
    return max(l, r);
}

int minIncrements(int n, vector<int>& cost) {
    int idx = 0;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(cost[idx++]);
    q.push(root);

    while (idx < n) {
        TreeNode* cur = q.front(); q.pop();
        cur->left = new TreeNode(cost[idx++]);
        cur->right = new TreeNode(cost[idx++]);
        q.push(cur->left);
        q.push(cur->right);
    }

    int ans = dfsToMinIncrements(root);
    return minInc;
}
};