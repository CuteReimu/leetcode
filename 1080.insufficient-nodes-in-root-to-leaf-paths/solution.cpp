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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (nullptr == root)
            return nullptr;
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val < limit) {
                return nullptr;
            }
            return root;
        }
        if (root->left != nullptr) root->left = sufficientSubset(root->left, limit - root->val);
        if (root->right != nullptr) root->right = sufficientSubset(root->right, limit - root->val);
        if (root->left == nullptr && root->right == nullptr) return nullptr;
        return root;
    }
};
