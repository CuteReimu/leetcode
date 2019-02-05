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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<pair<TreeNode *, unsigned char>> cache;
        cache.push(make_pair(root, 0));
        vector<int> result;
        while (!cache.empty())
        {
            auto &t = cache.top();
            if (t.second == 2)
            {
                cache.pop();
            } else if (t.second == 1)
            {
                t.second = 2;
                if (t.first != nullptr)
                {
                    cache.push(make_pair(t.first->right, 0));
                    result.push_back(t.first->val);
                }
            } else
            {
                t.second = 1;
                if (t.first != nullptr)
                    cache.push(make_pair(t.first->left, 0));
            }
        }
        return result;
    }
};
