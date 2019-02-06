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
	TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
		if (preorder.empty()) return nullptr;
		int val = preorder.front();
		TreeNode *head = new TreeNode(val);
		int i = 0;
		while (inorder[i] != val)
			i++;
		head->left = buildTree(vector<int>(preorder.begin() + 1, preorder.begin() + (i + 1)), vector<int>(inorder.begin(), inorder.begin() + i));
		head->right = buildTree(vector<int>(preorder.begin() + (i + 1), preorder.end()), vector<int>(inorder.begin() + (i + 1), inorder.end()));
		return head;
	}
};
