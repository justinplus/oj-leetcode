#include <iostream>
#include <algorithm>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    bool isBalanced(TreeNode* root) {
      size_t h = 0;
      return isBalanced( root, h );
    }

    bool isBalanced( TreeNode *nd, size_t &h ) {
      if( !nd ) {
       h = 0;
       return true;
      }

      size_t h_l = 0, h_r = 0;
      if( isBalanced( nd->left, h_l ) && isBalanced( nd->right, h_r ) )
        // NOTE: h_l, h_r is size_t
        if( (h_l >= h_r ? h_l - h_r : h_r - h_l) <= 1 ) {
          h = 1 + max( h_l, h_r );
          return true;
        }

      return false;
    }

};

int main() {
  TreeNode *r = new TreeNode(1);
  r->right = new TreeNode(2);
  Solution s;
  cout<<s.isBalanced(r);
  return 0;
}
