/**
 * Definition for a binary tree node.
 */
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    bool isValidBST(TreeNode* root) {
      if(!root) return true;

      if( isValidBST(root->left) && isValidBST(root->right) ){
        TreeNode *tmp = root->left;
        if(tmp) {
          for(; tmp->right; tmp = tmp->right);
          if(tmp->val >= root->val) return false; // Attention: '>' -> '>='
        }
        if( (tmp = root->right) ) {
          for(; tmp->left; tmp = tmp->left);
          if(tmp->val <= root->val) return false; // Attention '<' -> '<='
        }
        return true;
      }
      return false;

    }
};

int main() {
  Solution s;
  TreeNode *r = nullptr;
  cout<< s.isValidBST(r) <<endl; 
  r = new TreeNode(8);
  cout<< s.isValidBST(r) <<endl;
  r->left = new TreeNode(9);
  cout<< s.isValidBST(r) <<endl;
  r->left = new TreeNode(3);
  r->right = new TreeNode(11);
  cout<< s.isValidBST(r) <<endl;
  r->right->left = new TreeNode(4);
  cout<< s.isValidBST(r) <<endl;
  r->right->left = new TreeNode(9);
  cout<< s.isValidBST(r) <<endl;
  r->right->right = new TreeNode(12);
  cout<< s.isValidBST(r) <<endl; 
  
  // the case that fails initially: [1, 1] should be false
  r = new TreeNode(1);
  r->left = new TreeNode(1);
  cout<< s.isValidBST(r);

  return 0;
}
