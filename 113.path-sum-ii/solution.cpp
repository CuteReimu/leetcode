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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        list<int> cur;
        pathSum(result, cur, root, sum);
        return result;
    }
private:
    void pathSum(vector<vector<int>> &result, list<int> &cur, TreeNode *root, int sum) {
        if (!root) return;
        if (!root->left && !root->right)
        {
            if (sum == root->val)
            {
                result.emplace_back(cur.begin(), cur.end());
                result.back().push_back(sum);
            }
        } else
        {
            cur.push_back(root->val);
            pathSum(result, cur, root->left, sum - root->val);
            pathSum(result, cur, root->right, sum - root->val);
            cur.pop_back();
        }
    }
};
