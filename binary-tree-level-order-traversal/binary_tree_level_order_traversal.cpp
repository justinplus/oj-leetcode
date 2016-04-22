#include <iostream>
#include <vector>
#include <queue>
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
    // TODO: review, using queue#swap
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> res;

      queue<TreeNode *> q1, q2;
      TreeNode * cur;
      if(root) q1.push(root);

      while( !q1.empty() ) {
        res.push_back({});
        while( !q1.empty() ) {
          cur = q1.front();
          q1.pop();

          res.back().push_back(cur->val);
          if(cur->left) q2.push(cur->left);
          if(cur->right) q2.push(cur->right);
        }
        q1.swap(q2);
      }

      return res;
    }
};

int main() {
  return 0;
}
