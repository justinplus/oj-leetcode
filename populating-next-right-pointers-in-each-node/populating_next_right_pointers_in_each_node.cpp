#include <iostream>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
  public:
    void connect(TreeLinkNode *root) {
      if(!root) return;
      
      int cnt = 1;
      while( root->left ) {
        TreeLinkNode *p = root, *n = root->left;
        for(int i = 0; i < cnt; ++i ) {
          n->next = p->right;
          n = n->next;
          p = p->next;
          if( p ) {
            n->next = p->left;
            n = n->next;
          }
        }
        root = root->left;
        cnt *= 2;
      }
    }
};

int main() {
  TreeLinkNode* root = new TreeLinkNode(1);
  root->left = new TreeLinkNode(2);
  root->right = new TreeLinkNode(3);
  root->left->left = new TreeLinkNode(4);
  root->left->right = new TreeLinkNode(5);
  root->right->left = new TreeLinkNode(6);
  root->right->right = new TreeLinkNode(7);

  Solution s;
  s.connect(nullptr);

  while(root) {
    TreeLinkNode *n = root;
    for(; n; n = n->next) cout<<n->val<<' ';
    cout<<endl;
    root = root->left;
  }

  return 0;
}
