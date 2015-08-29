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
    int kthSmallest(TreeNode* root, int k) {
      vector<TreeNode*> path;
      TreeNode* cur = nullptr;
      for( ; root; path.push_back(root), root = root->left );

      while( path.size() ) {
        cur = path.back();
        if(--k == 0) return path.back()->val;
        
        if(cur->right) for(root = cur->right; root; path.push_back(root), root = root->left);
        else {
          int i = path.size()-2;
          for( ; i >= 0; i-- )
            if( path[i]->left == path[i+1] ) break;
          path.resize(i+1);
        }
      }
      // return 0;
    }
};

int main() {
  TreeNode *r = new TreeNode(8);
  r->left = new TreeNode(3);
  r->left->left = new TreeNode(1);
  r->right = new TreeNode(11);
  r->right->left = new TreeNode(9);
  r->right->right = new TreeNode(12);
  Solution s;
  for(int i = 0; i < 6; i++) {
    cout<< s.kthSmallest(r, i+1)<<endl;
  }
  return 0;
}
