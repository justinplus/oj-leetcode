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
    TreeNode* sortedArrayToBST(vector<int>& nums) {

      TreeNode *root = sortedArrayToBST(nums, 0, nums.size()-1);
      return root;
    }
          

    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
      if( l > r) return nullptr;

      int m = (l+r) / 2;
      TreeNode* nd = new TreeNode(nums[m]);
      nd->left = sortedArrayToBST(nums, l, m-1);
      nd->right = sortedArrayToBST(nums, m+1, r);
      return nd;
    }
};

void preorder(TreeNode *cur) {
  if(cur) {
    cout<<cur->val<<endl;
    preorder(cur->left);
    preorder(cur->right);
  }
}


int main() {
  vector<int> vec = {1,2,3,4,5};
  Solution s;
  TreeNode *r = s.sortedArrayToBST(vec);
  preorder(r);

  return 0;
}
