/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public int rec_ConvertBST(TreeNode root, int val)
{
    if (root == null) return 0;

    int rVal = rec_ConvertBST(root.right, val);
val = rVal == 0 ? val : rVal;
val += root.val;
root.val = val;
int lVal = rec_ConvertBST(root.left, val);
val = lVal == 0 ? val : lVal;

    return val;
}

public TreeNode ConvertBST(TreeNode root)
{
    rec_ConvertBST(root, 0);
    return root;
}
}