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
		return buildTree(preorder, 0, inorder, 0, preorder.size());
	}
private:
	TreeNode* buildTree(const vector<int>& preorder, int prebeg, const vector<int>& inorder, int inorderbeg, int len) {
		if (!len) return nullptr;
		int val = preorder[prebeg];
		TreeNode *head = new TreeNode(val);
		int i = inorderbeg;
		while (inorder[i] != val)
			i++;
		head->left = buildTree(preorder, prebeg + 1, inorder, inorderbeg, i - inorderbeg);
		head->right = buildTree(preorder, prebeg + 1 + i - inorderbeg, inorder, i + 1, len - 1 - i + inorderbeg);
		return head;
	}
};
