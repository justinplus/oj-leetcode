#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
  public:
    BSTIterator(TreeNode *root) {
      for(; root; path.push_back(root), root = root->left);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      return path.size() > 0;
    }

    /** @return the next smallest number */
    int next() {
      // Suppose hadNext() has been invoked before!!!
      int val = path.back()->val;
      TreeNode *nd = path.back()->right;
      if(nd) {
        for(; nd; path.push_back(nd), nd = nd->left);
      } else {
        int i = path.size()-2;
        for(; i >= 0; i--) {
          if( path[i+1] == path[i]->left) break;
        }
        path.resize(i+1);
      }
      return val;
    } 
    
    vector<TreeNode *> path;
};

int main(){
  TreeNode *r = new TreeNode(8);
  r->left = new TreeNode(3);
  r->left->left = new TreeNode(1);
  r->right = new TreeNode(11);
  r->right->left = new TreeNode(9);
  r->right->right = new TreeNode(12);
  BSTIterator i = BSTIterator(r);
  while(i.hasNext()) cout<<i.next()<<' ';
  cout<<endl;
  return 0;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
