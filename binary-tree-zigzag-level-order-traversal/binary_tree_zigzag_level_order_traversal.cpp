#include <iostream>
#include <stack>
#include <vector>
#include <array>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      const int m = 2;
      array<stack<TreeNode *>, m> stacks;

      vector<vector<int>> res;
      TreeNode * nd;

      int i = 0;
      if(root) stacks[0].push(root);

      while( !stacks[i].empty() ) {
        res.push_back({});
        while(!stacks[i].empty()) {
          nd = stacks[i].top();
          res.back().push_back(nd->val);
          stacks[i].pop();
          if( i % m == 0 ) {
            if(nd->left) stacks[(i+1) % m].push(nd->left);
            if(nd->right) stacks[(i+1) % m].push(nd->right);
          } else {
            if(nd->right) stacks[(i+1) % m].push(nd->right);
            if(nd->left) stacks[(i+1) % m].push(nd->left);
          }
        }
        i = (i+1) % m;
      }

      return res;
    }
};

int main() {
  TreeNode *r = new TreeNode(3);
  r->left = new TreeNode(9);
  r->right = new TreeNode(20);
  r->right->left = new TreeNode(15);
  r->right->right = new TreeNode(7);

  Solution s;
  auto res = s.zigzagLevelOrder(r);
  for(auto & vec : res ) {
    for(auto n : vec ) cout<<n<<' ';
    cout<<endl;
  }
  return 0;
}
