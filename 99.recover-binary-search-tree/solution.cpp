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
private:
	TreeNode *first;
	TreeNode *last;
public:
	void recoverTree(TreeNode* root) {
		first = nullptr;
		last = nullptr;
		if (!__recoverTree(root) && first && last)
			swap(first->val, last->val);
	}
private:
	bool __recoverTree(TreeNode* root) {
		if (!root) return false;
		if (__recoverTree(root->left))
			return true;
		if (!first)
		{
			if (last && root->val < last->val)
				first = last;
		} else
		{
			if (root->val > first->val)
			{
				swap(first->val, last->val);
				return true;
			}
		}
		last = root;
		if (__recoverTree(root->right))
			return true;
		return false;
	}
};
