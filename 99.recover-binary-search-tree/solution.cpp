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
	void recoverTree(TreeNode* root) {
		if (!root) return;
		mainRoot = root;
		recoverOneTree(root);
	}
private:
	TreeNode *mainRoot;
	bool recoverOneTree(TreeNode *root)
	{
		if (root->left && (recoverTreeNode(root->left, root) || recoverOneTree(root->left)))
			return true;
		if (root->right && (recoverTreeNode(root->right, root) || recoverOneTree(root->right)))
			return true;
		if (root->left && root->right && recoverTreeTree(root->left, root->right))
			return true;
		return false;
	}
	bool recoverTreeTree(TreeNode *root1, TreeNode *root2)
	{
		if (recoverTreeNode(root1, root2) || recoverTreeNode(root2, root1))
			return true;
		if (root1->left && root2->left && recoverTreeTree(root1->left, root2->left))
			return true;
		if (root1->left && root2->right && recoverTreeTree(root1->left, root2->right))
			return true;
		if (root1->right && root2->left && recoverTreeTree(root1->right, root2->left))
			return true;
		if (root1->right && root2->right && recoverTreeTree(root1->right, root2->right))
			return true;
		return false;
	}
	bool recoverTreeNode(TreeNode *root1, TreeNode *root2)
	{
		if (recoverNodeNode(root1, root2))
			return true;
		if (root1->left && recoverTreeNode(root1->left, root2))
			return true;
		if (root1->right && recoverTreeNode(root1->right, root2))
			return true;
		return false;
	}
	bool recoverNodeNode(TreeNode *root1, TreeNode *root2)
	{
		if (!root1 || !root2)
			return false;
		swap(root1->val, root2->val);
		if (isValidBST(mainRoot, LLONG_MIN, LLONG_MAX))
			return true;
		swap(root1->val, root2->val);
		return false;
	}
	bool isValidBST(TreeNode* root, long long bigThan, long long smallThan)
	{
		if (!root) return true;
		if (root->val <= bigThan || root->val >= smallThan) return false;
		return isValidBST(root->left, bigThan, root->val) && isValidBST(root->right, root->val, smallThan);
	}
};
