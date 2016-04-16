#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      return buildTree( inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
        int in_bg, int in_bk, int post_bg, int post_bk) {

      if( in_bg > in_bk ) return nullptr;

      int val = postorder[post_bk];
      TreeNode * nd = new TreeNode(val);
      int pos = in_bg;

      // assume always found
      for( ; pos <= in_bk; ++pos) if( inorder[pos] == val ) break;
      // assert( pos != in_bk + 1);

      nd->left = buildTree(inorder, postorder, in_bg, pos-1, post_bg, post_bg+pos-in_bg-1);
      nd->right = buildTree(inorder, postorder, pos+1, in_bk, post_bg+pos-in_bg, post_bk-1);

      return nd;
    }
};

int main() {
  return 0;
}
