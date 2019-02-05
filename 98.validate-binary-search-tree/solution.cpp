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
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, LLONG_MIN, LLONG_MAX);
	}
private:
	bool isValidBST(TreeNode* root, long long bigThan, long long smallThan)
	{
		if (!root) return true;
		if (root->val <= bigThan || root->val >= smallThan) return false;
		return isValidBST(root->left, bigThan, root->val) && isValidBST(root->right, root->val, smallThan);
	}
};
