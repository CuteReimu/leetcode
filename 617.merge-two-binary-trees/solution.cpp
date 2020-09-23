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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2)
            return nullptr;
        int val = 0;
        if (t1) val += t1 -> val;
        if (t2) val += t2 -> val;
        TreeNode *t = new TreeNode(val);
        t->left = mergeTrees(t1 ? t1 -> left : nullptr, t2 ? t2 -> left : nullptr);
        t->right = mergeTrees(t1 ? t1 -> right : nullptr, t2 ? t2 -> right : nullptr);
        return t;
    }
};
