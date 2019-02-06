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
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		int result = 1;
		list<TreeNode *> cache(1, root);
		int one = 1, two = 0;
		while (!cache.empty())
		{
			if (!one)
			{
				one = two;
				two = 0;
			result++;
			}
			TreeNode *top = cache.front();
			cache.pop_front();
			one--;
			if (top->left)
			{
				cache.push_back(top->left);
				two++;
			}
			if (top->right)
			{
				cache.push_back(top->right);
				two++;
			}
		}
		return result;
	}
};
