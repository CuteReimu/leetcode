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
    void flatten(TreeNode* root) {
        _flatten(root);
    }
private:
	TreeNode *_flatten(TreeNode *root) {
		if (!root) return nullptr;
		TreeNode *tmp = root->right;
		root->right = root->left;
		root->left = nullptr;
		TreeNode *p = _flatten(root->right);
		if (!tmp) return p ? p : root;
		if (p)
			p->right = tmp;
		else
			root->right = tmp;
		return _flatten(tmp);
	}
};
