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
        if (!root) return vector<int>();
        list<int> resultlist;
        stack<TreeNode*> cache;
        cache.push(root);
        while (!cache.empty()) {
            TreeNode *p = cache.top();
            cache.pop();
            resultlist.push_front(p->val);
            if (p->left) cache.push(p->left);
            if (p->right) cache.push(p->right);
        }
        return vector<int>(resultlist.begin(), resultlist.end());
    }
};
