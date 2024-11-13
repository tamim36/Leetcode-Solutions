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
    int MaxPathSumVal = int.MinValue;

public int MaxPathSumRec(TreeNode root)
{
    if (root == null)
{
    //Console.WriteLine(int.MinValue);
    return int.MinValue;
}
    
if (root.left == null && root.right == null)
{
    MaxPathSumVal = Math.Max(MaxPathSumVal, root.val);
    return root.val;
}

int l = MaxPathSumRec(root.left);
int r = MaxPathSumRec(root.right);
MaxPathSumVal = Math.Max(MaxPathSumVal, Math.Max(l, Math.Max(r, root.val)));
int la = (l == int.MinValue ? 0 : l);
int ra = (r == int.MinValue ? 0 : r);
MaxPathSumVal = Math.Max(MaxPathSumVal, la + ra + root.val);
MaxPathSumVal = Math.Max(MaxPathSumVal, Math.Max(la + root.val, ra + root.val));

return root.val + (Math.Max(l, r) < 0 ? 0 : Math.Max(l, r));
}

public int MaxPathSum(TreeNode root)
{
    MaxPathSumRec(root);
    return MaxPathSumVal;
}
}