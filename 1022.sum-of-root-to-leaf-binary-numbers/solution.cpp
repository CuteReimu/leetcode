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
    int sumRootToLeaf(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        mod = 1000000007;
        return sumRootToLeaf(root, 0);
    }
private:
    int sumRootToLeaf(TreeNode* root, int last) {
        int m = (root->val + last) % mod;
        if (root->left == nullptr && root->right == nullptr)
            return m;
        m = (m * 2) % mod;
        int n = 0;
        if (root->left != nullptr)
            n += sumRootToLeaf(root->left, m);
        if (root->right != nullptr)
            n += sumRootToLeaf(root->right, m);
        return n % mod;
    }
private:
    int mod;
};
