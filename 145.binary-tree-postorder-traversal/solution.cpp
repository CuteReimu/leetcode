/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return vector<int>();
		stack<TreeNode *> s;
		s.push(root);
		vector<int> vec;
		while (!s.empty()) {
			auto top = s.top();
			if (!top->right && !top->left) {vec.push_back(top->val); s.pop();}
			if (top->right) {s.push(top->right); top->right = nullptr;}
			if (top->left) {s.push(top->left); top->left = nullptr;}
		}
		return vec;
	}
};
