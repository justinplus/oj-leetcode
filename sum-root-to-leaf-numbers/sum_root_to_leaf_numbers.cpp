#include <iostream>
#include <vector>
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
    int sumNumbers(TreeNode* root) {
      int sum = 0;
      vector<TreeNode*> path;

      // using inorder traversal
      for(; root; path.push_back(root), root = root->left);

      while( path.size() ) {
        if( path.back()->right ) 
          for(root = path.back()->right; root; path.push_back(root), root = root->left);
        else {
          if(!path.back()->left) sum += rootLeafNumber( path ); // Attn: sum unless path.back()->left ??!!
          int i = path.size() - 2;
          for(; i >=0; i--) {
            if( path[i]->left == path[i+1] ) break;
          }
          path.resize(i+1);
        }
      }
      return sum;
    }

    int rootLeafNumber( const vector<TreeNode*> & v ) {
      int mul = 1;
      int res = 0;
      for(int i = v.size()-1; i >= 0; i--) { // Attn: unsigned -> int, why ??!!
        res += mul * v[i]->val;
        mul *= 10;
      }
      return res;
    }
};


int main() {
  TreeNode * r = new TreeNode(1);
  r->left = new TreeNode(2);
  r->right = new TreeNode(3);
  r->left->left = new TreeNode(1);
  r->right->left = new TreeNode(0);

  Solution s;

  cout<<s.sumNumbers(r)<<endl;
  return 0;
}
