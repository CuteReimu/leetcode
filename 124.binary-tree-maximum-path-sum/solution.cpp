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
	int maxPathSum(TreeNode* root) {
		if (!root) return 0;
		return _maxPathSum(root).first;
	}
private:
	pair<int, int> _maxPathSum(TreeNode* root) {
		pair<int, int> p;
		if (root->left)
		{
			if (root->right)
			{
				pair<int, int> p1 = _maxPathSum(root->left);
				pair<int, int> p2 = _maxPathSum(root->right);
				int val1 = max(p1.second + root->val, p2.second + root->val);
				val1 = max(val1, root->val);
				int val2 = max(p1.first, p2.first);
				val2 = max(p1.second + p2.second + root->val, val2);
				if (val2 < val1) val2 = val1;
				return make_pair(val2, val1);
			} else
				p = _maxPathSum(root->left);
		} else if (root->right)
			p = _maxPathSum(root->right);
		else
			return make_pair(root->val, root->val);
		int val1 = p.second > 0 ? p.second + root->val : root->val;
		int val2 = p.first;
		return make_pair(val2 < val1 ? val1 : val2, val1);
	}
};
