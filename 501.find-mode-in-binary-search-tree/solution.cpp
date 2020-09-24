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
private:
    int max_cnt = 0;
    vector<pair<int, int>> cache;
    void findMode2(TreeNode* root) {
        if (!root) return;
        findMode2(root->left);
        if (cache.size() == 0 || root->val != cache.back().first) {
			if (cache.size() != 0)
                max_cnt = max(max_cnt, cache.back().second);
            cache.emplace_back(root->val, 1);
        } else {
            cache.back().second++;
        }
        findMode2(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        if (!root) return vector<int>();
        findMode2(root);
        max_cnt = max(max_cnt, cache.back().second);
        vector<int> result;
        for (auto &p : cache)
            if (p.second == max_cnt)
                result.push_back(p.first);
        return result;
    }
};
