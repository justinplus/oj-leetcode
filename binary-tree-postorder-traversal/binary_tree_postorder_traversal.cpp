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
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> output;
      TreeNode *cur = nullptr, dummy(0);
      vector<TreeNode *> path(1, &dummy); // use dummy node

      for(; root; path.push_back(root), root = root->left);

      while(path.size() > 1) {
        cur = path.back();
        if(cur->left) path.push_back(cur->left);
        else if(cur->right) path.push_back(cur->right);
        else {
          int i = path.size() - 2;
          for( ; i >= 0; i--) {
            cur = path[i+1];
            output.push_back(cur->val);
            path.pop_back();
            if(path[i]->left == cur && path[i]->right) {
              path.push_back(path[i]->right);
              break;
            }
          }
        }
      }
      return output;
    }

    vector<int> postorderRecursive(TreeNode* root) {
      vector<int> output;
      postorder(root, output);
      return output;
    }

    void postorder(TreeNode *cur, vector<int> & output) {
      if(cur) {
        postorder(cur->left, output);
        postorder(cur->right, output);
        output.push_back(cur->val);
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
  inspect(s.postorderTraversal(r));
  inspect(s.postorderRecursive(r));
  return 0;
}
