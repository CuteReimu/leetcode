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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int v;
        return sumOfLeftLeaves(root, v);
    }
private:
    int sumOfLeftLeaves(TreeNode* root, int &leafVal) {
        if (!root->left && !root->right) {
            leafVal = root->val;
            return 0;
        }
        leafVal = 0;
        int leftLeafVal = 0, rightLeafVal;
        int left = 0, right = 0;
        if (root->left)
            left = sumOfLeftLeaves(root->left, leftLeafVal);
        if (root->right)
            right = sumOfLeftLeaves(root->right, rightLeafVal);
        return left + right + leftLeafVal;
    }
};
