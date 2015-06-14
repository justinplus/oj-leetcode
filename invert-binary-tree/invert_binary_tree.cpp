/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if(root) {
			TreeNode* lc = root->left;
			root->left = invertTree(root->right);
			root->right = invertTree(lc);
		}
		return root;
	}
};

class Solution1 {
public:
	void invertTree(TreeNode* root) {
		if(root) {
			TreeNode* lc = root->left;
			root->left = root-right;
			root->right =  lc;
			invertTree(root->right);
			invertTree(root->left);
		}
	}
};

class Solution2 {
public:
	void invertTree(TreeNode* root) {
		if(root) {
			invertTree(root->right);
			invertTree(root->left);
			TreeNode* lc = root->left;
			root->left = root-right;
			root->right =  lc;
		}
	}
};