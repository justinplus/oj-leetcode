#include <iostream>
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
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    void flatten_r( TreeNode *r ) {
      if(r) flatten_recursive( r );
    }

    TreeNode* flatten_recursive( TreeNode *r) {
      if( !r->left && !r->right)
        return r;
      else {
        TreeNode *left_last = nullptr, *right_last = nullptr;
        if(r->right) right_last = flatten_recursive(r->right);
        if(r->left) {
          left_last = flatten_recursive(r->left);
          left_last->right = r->right;
          r->right = r->left;
          r->left = nullptr;
        }

        return right_last ? right_last : left_last;
      }
    }

    void flatten(TreeNode* root) {
      TreeNode *cur, *tmp, dummy(0); // Attn: * use before every name
      vector<array<TreeNode*, 3>> path(1, {&dummy, nullptr, nullptr}); // use dummy node
      array<TreeNode*, 3> nd;

      for(; root; path.push_back({root, nullptr, nullptr}), root = root->left);

      while( path.size() > 1 ) {
        cur = path.back()[0];
        if(cur->left) path.push_back({cur->left, nullptr, nullptr});
        else if(cur->right) path.push_back({cur->right, nullptr, nullptr});
        else {
          int i = path.size()-2;
          for( ; i >= 0; i--) {
            nd = path[i+1];
            path.pop_back();
            if( nd[1] ) {
              nd[1]->right = nd[0]->right;
              nd[0]->right = nd[0]->left;
              nd[0]->left = nullptr;
              tmp = nd[2] ? nd[2] : nd[1];
            } else {
              tmp = nd[2] ? nd[2] : nd[0];
            }
            if( path[i][0]->left == nd[0]) {
              path[i][1] = tmp;
              if( path[i][0]->right ){
                path.push_back({path[i][0]->right, nullptr, nullptr});
                break;
              }
            } else {
              path[i][2] = tmp;
            }
          }
        }
      }
    }
};

void inspect( TreeNode* r ) {
  while(r) {
    cout<<r->val<<' ';
    r = r->right;
  }
  cout<<endl;
}

int main() {
  TreeNode* r = new TreeNode(1);
  r->left = new TreeNode(2);
  r->right = new TreeNode(5);
  r->left->left = new TreeNode(3);
  r->left->right = new TreeNode(4);
  r->right->right = new TreeNode(6);

  Solution s;
  s.flatten(r);
  inspect(r);

  // vector<int[2]> v; Attn: Think why the vector<int[2]> do not work here!?
  // v.push_back({1,2});
  // array<int, 2> arr;
  // arr.push_back({1,2});
  return 0;
}
