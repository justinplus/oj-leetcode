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
    // using inorder traversal; TODO: may not be the best solution
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      vector<vector<int>> res;
      vector<TreeNode*> path;
      TreeNode* cur = nullptr;
      int s = 0;

      if(root) path.push_back(root);

      while( path.size() ) {
        cur = path.back();
        if(cur->left) path.push_back(cur->left);
        else if(cur->right) path.push_back(cur->right);
        else {
          s = 0;
          for(auto nd : path) s += nd->val;
          if( s == sum ) {
            res.push_back(vector<int>());
            for(auto nd : path)
              res.back().push_back(nd->val);
          }

          // int i = path.size() - 2;
          // for(; i >= 0; i--)
            // if(path[i]->left == path[i+1] && path[i]->right) {
              // path.pop_back();
              // path.push_back(path[i]->right);
              // break;
            // } else {
              // path.pop_back();
            // }
          // if(i == -1) path.pop_back();

          int i = path.size() - 2;
          for(; i >= 0; i--)
            if( path[i]->left == path[i+1] && path[i]->right )
              break;

          path.resize(i+1);
          if(!path.empty()) path.push_back(path[i]->right);

        }
      }
      return res;
    }
};

void inspect( const vector<vector<int>> & v ) {
  for(unsigned i = 0; i < v.size(); i++) {
    for(unsigned j = 0; j<v[i].size(); j++) {
      cout<<v[i][j]<<' ';
    }
    cout<<endl;
  }
}

int main() {
  TreeNode* r = new TreeNode(5);
  r->left = new TreeNode(4);
  r->right = new TreeNode(8);
  r->left->left = new TreeNode(11);
  r->left->left->left = new TreeNode(7);
  r->left->left->right = new TreeNode(2);
  r->right->left = new TreeNode(13);
  r->right->right = new TreeNode(4);
  r->right->right->left = new TreeNode(5);
  r->right->right->right = new TreeNode(1);
  Solution s;
  inspect( s.pathSum(r, 22));
  return 0;
}
