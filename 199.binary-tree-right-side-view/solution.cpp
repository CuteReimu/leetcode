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
	vector<int> rightSideView(TreeNode* root) {
		if (root == nullptr) return vector<int>();
		queue<pair<TreeNode *, int>> q;
		int height = 1;
		q.emplace(root, 1);
		vector<int> result;
		while (!q.empty()) {
			pair<TreeNode *, int> p = q.front();
			q.pop();
			if (q.empty() || q.front().second > height) {
				height++;
				result.push_back(p.first->val);
			}
			if (p.first->left != nullptr) q.emplace(p.first->left, p.second + 1);
			if (p.first->right != nullptr) q.emplace(p.first->right, p.second + 1);
		}
		return result;
	}
};
