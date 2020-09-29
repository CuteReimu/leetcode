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
    int diameterOfBinaryTree(TreeNode* root) {
        int i;
        return diameterOfBinaryTree(root, i);
    }
private:
    int diameterOfBinaryTree(TreeNode* root, int &height) {
        if (!root) {
            height = 0;
            return 0;
        }
        int heightleft, heightright;
        int leftdiameter = diameterOfBinaryTree(root->left, heightleft);
        int rightdiameter = diameterOfBinaryTree(root->right, heightright);
        height = max(heightleft, heightright) + 1;
        return max(heightleft + heightright, max(leftdiameter, rightdiameter));
    }
};
