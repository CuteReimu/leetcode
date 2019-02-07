/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
	struct MyTreeNode : public TreeNode
	{
		MyTreeNode (int val) : height(0), TreeNode(val) {}
		int height;
	};
public:
	TreeNode* sortedListToBST(ListNode *head) {
		TreeNode *root = nullptr;
		while (head)
		{
			root = addNode(root, head->val);
			head = head->next;
		}
		return root;
	}
private:
	TreeNode* addNode(TreeNode *root, int val) {
		if (!root)
		{
			MyTreeNode *result = new MyTreeNode(val);
			result->height = 1;
			return result;
		}
		root->right = addNode(root->right, val);
		if ((root->left ? ((MyTreeNode *)root->left)->height + 2 : 2) == ((MyTreeNode *)root->right)->height)
		{
			TreeNode *tmp = root->right;
			root->right = tmp->left;
			tmp->left = root;
			((MyTreeNode *)root)->height = max(root->left ? ((MyTreeNode *)root->left)->height : 0, root->right ? ((MyTreeNode *)root->right)->height : 0) + 1;
			root = tmp;
		}
		((MyTreeNode *)root)->height = max(root->left ? ((MyTreeNode *)root->left)->height : 0, root->right ? ((MyTreeNode *)root->right)->height : 0) + 1;
		return root;
	}
};
