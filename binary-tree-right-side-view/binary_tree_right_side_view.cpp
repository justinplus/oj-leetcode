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
    // level traverse
    vector<int> rightSideView_level(TreeNode* root) {
      vector<int> res;
      queue<TreeNode*> q1, q2;
      if(root) q1.push(root);
      TreeNode *nd;

      while( !q1.empty() ) {
        res.push_back(q1.front()->val);
        while( !q1.empty() ) {
          nd = q1.front();
          q1.pop();
          if( nd->right ) q2.push(nd->right);
          if( nd->left ) q2.push(nd->left);
        }
        q1.swap(q2);
      }
      return res;
    }
};

int main() {
  return 0;
}
