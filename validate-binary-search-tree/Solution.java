/**
 * Definition for a binary tree node.
 */
class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;
  TreeNode(int x) { val = x; }
}

public class Solution {
  public boolean isValidBST(TreeNode root) {
    if( root == null ) return true;

    if( isValidBST(root.left) && isValidBST(root.right) ) {
      TreeNode p = root.left;
      if( (p = root.left) != null ) {
        for(; p.right != null; p = p.right );
        // NOTE: '<' or '<='
        if( root.val <= p.val ) return false;
      }
      if( (p = root.right) != null ) {
        for(; p.left != null; p = p.left );
        if( root.val >= p.val ) return false;
      }
      return true;
    }

    return false;
  }
}
