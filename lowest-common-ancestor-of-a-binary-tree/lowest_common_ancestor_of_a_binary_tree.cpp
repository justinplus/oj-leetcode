#include<iostream>
#include<vector>
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
  using NodeVec = vector<TreeNode*>;
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      NodeVec a1 = ancestors(root, p);
      NodeVec a2 = ancestors(root, q);
      // NOTE: dummy node is not good when nodes hold huge data
      TreeNode dummy1(0), dummy2(0);
      a1.push_back(&dummy1);
      a2.push_back(&dummy2);

      for(unsigned i = 0; i < a1.size() && i < a2.size(); ++i)
        if(a1[i] != a2[i]) return a1[i-1];

      return root;
    }

    NodeVec ancestors(TreeNode* root, TreeNode* p) {
      NodeVec path;
      if(root) path.push_back(root);
      TreeNode * n = nullptr;
      while(!path.empty()) {
        n = path.back();
        if( n == p) {
          return path;
        }
        else 
          if( n->left != nullptr ) path.push_back(n->left);
          else if( n->right != nullptr) path.push_back(n->right);
          else {
            int i = path.size() - 2;
            for( ;  i >= 0; --i )
              if( path[i]->right != path[i+1] && path[i]->right )
                break;
            
            path.resize(i+1);
            if(!path.empty()) path.push_back(path[i]->right);
          }
      }
      return {};
    }
};

void inspect(const vector<TreeNode*> & vec) {
  for(auto nd : vec) 
    cout<<nd->val<<' ';
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
  inspect(s.ancestors(r, r->left));
  inspect(s.ancestors(r, r->left->left));
  auto n = s.lowestCommonAncestor(r, r->left->left, r->left->left);
  cout<<n->val<<endl;
  return 0;
}
