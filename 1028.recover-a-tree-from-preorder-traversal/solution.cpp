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
    TreeNode* recoverFromPreorder(string S) {
        return recoverFromPreorder(S, 0, S.size(), 1);
    }
private:
    TreeNode* recoverFromPreorder(const string &S, int beg, int end, int i) {
        if (end <= beg) return nullptr;
        stringstream ss;
		int j = beg;
        for (; j < end && S[j] != '-'; j++) {
            ss << S[j];
        }
        int val;
        ss >> val;
        TreeNode* node = new TreeNode(val);
		if (j == end) return node;
        int beg1 = -1, beg2 = -1, end1 = -1, end2 = -1;
        for (; j < end; j++) {
            if (S[j] != '-' || j > beg && S[j - 1] == '-') {
                continue;
            }
            if (S[j + i] != '-') {
                if (beg1 == -1) {
                    beg1 = j + i;
                } else {
                    end1 = j;
                    beg2 = j + i;
                }
                j += i;
            }
        }
        if (end1 == -1) {
            end1 = end;
            node->left = recoverFromPreorder(S, beg1, end1, i+1);
        } else {
            end2 = end;
            node->left = recoverFromPreorder(S, beg1, end1, i+1);
            node->right = recoverFromPreorder(S, beg2, end2, i+1);
        }
        return node;
    }
};
