#include <iostream>
#include <vector>
#include <numeric>
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
    // 12ms
    bool hasPathSum(TreeNode* root, int sum) {
      vector<TreeNode*> stk;
      TreeNode *nd;

      int s = 0;
      if(root) {
        stk.push_back(root);
        s += root->val;
      }

      while( !stk.empty() ) {
        nd = stk.back();

        if( nd->left ) { stk.push_back(nd->left); s += nd->left->val; }
        else if( nd->right ) { stk.push_back(nd->right); s += nd->right->val; }
        else {
          // int s = accumulate(stk.begin(), stk.end(), 0, [](const int part_sum, const TreeNode *nd){ return part_sum + nd->val; } );

          if( s == sum ) return true;

          int i = stk.size() - 2;
          for( ; i >= 0; --i )
            if( stk[i]->left == stk[i+1] && stk[i]->right != nullptr ) break;
          for( int k = i+1; k < (int) stk.size(); ++k )
            s -= stk[k]->val;

          stk.resize(i+1);
          if(!stk.empty()) { stk.push_back(stk[i]->right); s += stk[i]->right->val; }
        }
      }

      return false;
    }

    // 16ms
    bool hasPathSum_16ms(TreeNode* root, int sum) {
      vector<TreeNode*> stk;
      if(root) stk.push_back(root);
      TreeNode *nd;

      while( !stk.empty() ) {
        nd = stk.back();

        if( nd->left ) stk.push_back(nd->left);
        else if( nd->right ) stk.push_back(nd->right);
        else {
          int s = accumulate(stk.begin(), stk.end(), 0,
              [](const int part_sum, const TreeNode *nd){ return part_sum + nd->val; } );

          if( s == sum ) return true;

          int i = stk.size() - 2;
          for( ; i >= 0; --i )
            if( stk[i]->left == stk[i+1] && stk[i]->right != nullptr ) break;
          stk.resize(i+1);
          if(!stk.empty()) stk.push_back(stk[i]->right);
        }
      }

      return false;
    }
};

int main() {
  return 0;
}
