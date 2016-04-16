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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      return buildTree( preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
        int pre_bg, int pre_bk, int in_bg, int in_bk) {

      if( in_bg > in_bk ) return nullptr;

      int val = preorder[pre_bg];
      TreeNode * nd = new TreeNode(val);
      int pos = in_bg;

      // assume always found
      for( ; pos <= in_bk; ++pos) if( inorder[pos] == val ) break;
      // assert( pos != in_bk + 1);

      nd->left = buildTree(preorder, inorder, pre_bg+1, pre_bg + pos - in_bg, in_bg, pos-1);
      nd->right = buildTree(preorder, inorder, pre_bg + pos - in_bg + 1, pre_bk, pos+1, in_bk);

      return nd;
    }
};

int main() {
  return 0;
}
