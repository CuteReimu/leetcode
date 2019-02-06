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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int beg, int end) {
        if (beg == end) return nullptr;
        int mid = (beg + end - 1) / 2;
        TreeNode *head = new TreeNode(nums[mid]);
        head->left = sortedArrayToBST(nums, beg, mid);
        head->right = sortedArrayToBST(nums, mid + 1, end);
        return head;
    }
};
