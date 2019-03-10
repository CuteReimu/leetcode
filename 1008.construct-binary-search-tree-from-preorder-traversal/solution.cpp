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
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		return bstFromPreorder(preorder, preorder.begin(), preorder.end());
	}
private:
	TreeNode* bstFromPreorder(vector<int>& preorder, vector<int>::const_iterator begin, vector<int>::const_iterator end) {
		if (begin == end) return nullptr;
		TreeNode *p = new TreeNode(*begin);
		auto it = begin + 1;
		for (; it != end; it++)
			if (*it > p->val) break;
		p->left = bstFromPreorder(preorder, begin + 1, it);
		p->right = bstFromPreorder(preorder, it, end);
		return p;
	}
};
