#include <iostream>
#include <algorithm>
#include <climits>
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
    int minDepth(TreeNode* root) {
      if( !root ) return 0;

      if( !root->left )
        return 1 + minDepth(root->right);
      else if( !root->right )
        return 1 + minDepth(root->left);
      else
        return 1 + min( minDepth(root->left), minDepth(root->right) );
    }

    // preorder & pruning
    int minDepth_prune( TreeNode *root ) {
      if( !root ) return 0;

      size_t min_depth = UINT_MAX;
      minDepth_prune( root, 1, min_depth);
      return min_depth;
    }

    void minDepth_prune( TreeNode *root, size_t depth, size_t &min_depth ) {
      if( !root->left && !root->right ) min_depth = depth;
      else {
        if( depth < min_depth ) {
          if(root->left) minDepth_prune(root->left, depth + 1, min_depth);
          if(root->right) minDepth_prune(root->right, depth + 1, min_depth);
        }
      }
    }
};

int main() {
  return 0;
}
