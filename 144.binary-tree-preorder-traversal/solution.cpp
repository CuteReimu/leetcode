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
    vector<int> preorderTraversal(TreeNode* root) {
        _preorderTraversal(root);
        return result;
    }
private:
    void _preorderTraversal(TreeNode* root) {
        if (!root) return;
        result.push_back(root->val);
        _preorderTraversal(root->left);
        _preorderTraversal(root->right);
    }
    vector<int> result;
};
