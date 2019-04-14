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
    int maxAncestorDiff(TreeNode* root) {
		maxresult = 0;
		cache.clear();
		_cal(root);
		return maxresult;
    }
private:
	void _cal(TreeNode* root) {
		auto it = cache.emplace(root->val, 0).first;
		it->second++;
		maxresult = max(maxresult, abs(cache.begin()->first - cache.rbegin()->first));
		if (root->left != nullptr) _cal(root->left);
		if (root->right != nullptr) _cal(root->right);
		if (--it->second == 0)
			cache.erase(it);
	}
private:
	map<int, int> cache;
	int maxresult;
};
