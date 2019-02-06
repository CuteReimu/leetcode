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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
		if (!root) return result;
		list<TreeNode *> cache(1, root);
		int one = 1, two = 0;
		result.emplace_back();
		while (!cache.empty())
		{
			if (!one)
			{
				result.emplace_back();
				one = two;
				two = 0;
			}
			TreeNode *top = cache.front();
			result.back().push_back(top->val);
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
        int len = result.size();
        for (int i = 1; i < len; i += 2)
			reverse(result[i].begin(), result[i].end());
		return result;
    }
};
