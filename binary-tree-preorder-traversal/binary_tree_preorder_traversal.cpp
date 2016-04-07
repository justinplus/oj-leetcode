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
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> output;
      vector<TreeNode *> path;
      if(root) path.push_back(root);

      while(!path.empty()) {
        TreeNode *cur = path.back();
        output.push_back(cur->val);

        if( cur->left ) path.push_back(cur->left);
        else if( cur ->right ) path.push_back(cur->right);
        else {
          int i = path.size() - 2;
          for(; i >= 0; i--)
            if( path[i]->left == path[i+1] && path[i]->right )
              break;

          path.resize(i+1);
          if(!path.empty()) path.push_back(path[i]->right);
        }
      }

      return output;
    }

    vector<int> preorderRecursive(TreeNode *root) {
      vector<int> output;
      preorder(root, output);
      
      return output;
    }

    void preorder(TreeNode *cur, vector<int> &output) {
      if(cur) {
        output.push_back(cur->val);
        preorder(cur->left, output);
        preorder(cur->right, output);
      }
    }
};

void inspect(const vector<int> &v) {
  for(unsigned i = 0; i < v.size(); i++) {
    cout<<v[i]<<' ';
  }
  cout<<endl;
}

int main() {
  TreeNode *r = new TreeNode(8);
  r->left = new TreeNode(3);
  r->left->left = new TreeNode(1);
  r->right = new TreeNode(11);
  r->right->left = new TreeNode(9);
  r->right->right = new TreeNode(12);
  Solution s;
  inspect(s.preorderTraversal(r));
  inspect(s.preorderRecursive(r));
  return 0;
}


