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
    vector<int> postorderTraversal(TreeNode* root) {
        _postorderTraversal(root);
        return result;
    }
private:
    void _postorderTraversal(TreeNode* root) {
        if (!root) return;
        _postorderTraversal(root->left);
        _postorderTraversal(root->right);
        result.push_back(root->val);
    }
    vector<int> result;
};
