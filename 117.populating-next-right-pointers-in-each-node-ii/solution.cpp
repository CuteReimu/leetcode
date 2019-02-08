/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *tmp = root->next;
        while (tmp)
        {
            if (tmp->left)
            {
                tmp = tmp->left;
                break;
            }
            if (tmp->right)
            {
                tmp = tmp->right;
                break;
            }
            tmp = tmp->next;
        }
        if (root->left)
        {
            root->left->next = root->right ? root->right : tmp;
        }
        if (root->right)
        {
            root->right->next = tmp;
        }
        connect(root->right);
        connect(root->left);
    }
};
