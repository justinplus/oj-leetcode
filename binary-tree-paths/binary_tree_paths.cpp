#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> paths;
      vector<TreeNode *> stk;
      if(root) stk.push_back(root);

      stringstream ss;
      TreeNode *nd;
      while( !stk.empty() ) {
        nd = stk.back();

        if( nd->left ) stk.push_back(nd->left);
        else if( nd->right ) stk.push_back(nd->right);
        else {
          for( size_t i = 0; i < stk.size() - 1; ++i ) ss<<stk[i]->val<<"->";
          ss<<stk.back()->val;
          paths.push_back(string());
          ss>>paths.back();
          ss.clear();

          size_t i = stk.size()-1;
          for( ; i > 0; --i)
            if( stk[i] == stk[i-1]->left && stk[i-1]->right ) break;

          stk.resize(i);
          if( !stk.empty() ) stk.push_back(stk.back()->right);
        }
      }

      return paths;
    }
};

int main() {
  TreeNode *r = new TreeNode(1);
  r->left = new TreeNode(2);
  r->right = new TreeNode(3);
  r->left->right = new TreeNode(5);

  Solution s;
  auto paths = s.binaryTreePaths(r);
  for( string& str : paths ) cout<<str<<endl;

  return 0;
}
