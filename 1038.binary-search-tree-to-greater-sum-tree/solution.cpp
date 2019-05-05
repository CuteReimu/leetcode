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
	TreeNode* bstToGst(TreeNode* root) {
		int i = 0;
		bstToGst(root, i);
		return root;
	}
private:
	void bstToGst(TreeNode* root, int &val) {
		if (root->right) bstToGst(root->right, val);
		val += root->val;
		root->val = val;
		if (root->left) bstToGst(root->left, val);
	}
};
