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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    // NOTE: TLE, if directly traverse the tree
    int countNodes_traverse(TreeNode* root) {
      int cnt = 0;
      preOrder(root, cnt);
      return cnt;
    }

    void preOrder(TreeNode* cur, int &cnt) {
      if( cur ) {
        ++cnt;
        preOrder(cur->left, cnt);
        preOrder(cur->right, cnt);
      }
    }

    // 424ms TODO: improve performance
    int countNodes(TreeNode* root) {
      TreeNode *nd = root;
      int h = 0;
      for( ; nd; nd = nd->left ) ++h;
      if(h == 0) return 0;

      int l = pow(h-1) - 1;
      int r = pow(h) - 2;
      int m = (l+r) / 2;

      vector<int> path(h-1);

      while( l <= r ) {
        m = (l+r) / 2;
        // cout<<"l: "<<l<<"; r: "<<r<<"; m: "<<m<<endl;
        nd = root;
        int tmp = m + 1;
        for( int i = 0; i < h - 1; i++ ) {
          path[h-i-2] = tmp % 2;
          tmp /= 2;
        }

        // for(auto n : path) cout<<n<<' ';
        // cout<<endl;

        int i = 0;

        for( ; i < h - 1; i++ ) {
          if( path[i] == 0 )
            nd = nd->left;
          else
            nd = nd->right;
        }

        if( nd )
          l = m + 1;
        else
          r = m - 1;
      }

      return nd == nullptr ? m : m + 1; // NOTE
    }

    static int pow(int exponent) {
      int res = 1;
      for( int i = 0; i < exponent; i++ ) res *= 2;
      return res;
    }
};

int main(){
  TreeNode * r = new TreeNode(0);
  r->left = new TreeNode(0);
  r->right = new TreeNode(0);
  r->left->left = new TreeNode(0);
  r->left->right = new TreeNode(0);
  r->right->left = new TreeNode(0);
  r->right->right = new TreeNode(0);
  r->left->left->left = new TreeNode(0);
  r->left->left->right = new TreeNode(0);
  r->left->right->left = new TreeNode(0);
  r->left->right->right = new TreeNode(0);
  r->right->left->left = new TreeNode(0);

  Solution s; 
  cout<<s.countNodes(r)<<endl;
  cout<<s.countNodes(nullptr)<<endl;


  return 0;
}
