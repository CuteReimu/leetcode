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
	TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder) {
		return buildTree(inorder, 0, postorder, 0, inorder.size());
	}
private:
	TreeNode* buildTree(const vector<int>& inorder, int inbeg, const vector<int>& postorder, int postbeg, int len) {
		if (!len) return nullptr;
		int val = postorder[postbeg + len - 1];
		TreeNode *head = new TreeNode(val);
		int i = inbeg;
		while (inorder[i] != val)
			i++;
		head->left = buildTree(inorder, inbeg, postorder, postbeg, i - inbeg);
		head->right = buildTree(inorder, i + 1, postorder, postbeg + i - inbeg, len - 1 - i + inbeg);
		return head;
	}
};
