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

      while( root ) {
        TreeLinkNode *up, *cur = nullptr;
        up = root;

        while( up ) {

          if( up->left ) {
            if( cur == nullptr ){
              cur = up->left;
              root = cur;
            }
            else {
              if( cur->next ) cur = cur->next;
              cur->next = up->left;
            }

            if( up->right ) {
              if( cur->next ) cur = cur->next;
              cur->next = up->right;
            }

          } else

            if(up->right) {
              if( cur == nullptr ) {
                cur = up->right;
                root = cur;
              }
              else {
                if( cur->next ) cur = cur->next;
                cur->next = up->right;
              }
            }

          up = up->next;
        }

        while( root && !root->left && !root->right ) root = root->next;
      }

    }
};

int main() {
  TreeLinkNode* root = new TreeLinkNode(1);
  root->left = new TreeLinkNode(2);
  root->right = new TreeLinkNode(3);
  root->left->left = new TreeLinkNode(4);
  // root->left->right = new TreeLinkNode(5);
  // root->right->left = new TreeLinkNode(6);
  root->right->right = new TreeLinkNode(7);

  Solution s;
  s.connect(root);

  while(root) {
    TreeLinkNode *n = root;
    for(; n; n = n->next) cout<<n->val<<' ';
    cout<<endl;
    while( root && !root->left && !root->right ) root = root->next;
    if( root ) root = root->left ? root->left : root->right;
  }

  return 0;
}
