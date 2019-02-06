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
		stack<pair<TreeNode *, unsigned char>> cache;
		cache.push(make_pair(root, 0));
		TreeNode *first = nullptr, *second = nullptr, *last = nullptr;
		while (!(cache.empty() || first && second))
		{
			pair<TreeNode *, unsigned char> &t = cache.top();
			switch (t.second)
			{
			case 0:
				t.second++;
				if (t.first->left)
				{
					cache.push(make_pair(t.first->left, 0));
					break;
				}
			case 1:
				t.second++;
				if (!first)
				{
					if (last && t.first->val < last->val)
						first = last;
				} else
				{
					if (t.first->val > first->val)
					{
						second = last;
						break;
					}
				}
				last = t.first;
				if (t.first->right)
				{
					cache.push(make_pair(t.first->right, 0));
					break;
				}
			case 2:
				cache.pop();
			}
		}
		if (first)
			swap(first->val, second ? second->val : last->val);
	}
};
