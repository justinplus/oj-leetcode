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
    // Iterative, similar to binary search tree iterator
    vector<int> inorderTraversal(TreeNode* root) {
      vector<TreeNode *> path;
      vector<int> output;

      for(; root; path.push_back(root), root = root->left);

      while( path.size() > 0 ) {
        output.push_back(path.back()->val);

        if(path.back()->right)
          for(root = path.back()->right; root; path.push_back(root), root = root->left);
        else {
          int i = path.size() - 2;
          for( ; i >= 0; i--) {
            if(path[i+1] == path[i]->left) break;
          }
          path.resize(i+1);
        }
      }
      return output;
    }

    // Recursive
    vector<int> inorderRecursive(TreeNode *root) {
      vector<int> output;
      inorder(root, output);
      return output;
    }

    void inorder(TreeNode *cur, vector<int> &output) {
      if(cur) {
        inorder(cur->left, output);
        output.push_back(cur->val);
        inorder(cur->right, output);
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
  inspect(s.inorderTraversal(r));
  inspect(s.inorderRecursive(r));
  return 0;
}


