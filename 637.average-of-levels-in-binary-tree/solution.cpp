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
	vector<double> averageOfLevels(TreeNode* root) {
		queue<const TreeNode *> queueNode;
		queue<int> queueLevel;
		int curLevel = 1;
		vector<int> levelVals;
		queueNode.push(root);
		queueLevel.push(1);
		vector<double> result;
		while (!queueNode.empty()) {
			const TreeNode* p = queueNode.front();
			queueNode.pop();
			int level = queueLevel.front();
			queueLevel.pop();
			if (level != curLevel) {
				long long sums = 0.0;
				for (int i : levelVals) {
					sums += (double) i;
				}
				result.push_back((double) sums / levelVals.size());
				levelVals.clear();
				curLevel = level;
			}
			levelVals.push_back(p->val);
			if (p->left) {
				queueNode.push(p->left);
				queueLevel.push(level + 1);
			}
			if (p->right) {
				queueNode.push(p->right);
				queueLevel.push(level + 1);
			}
		}
		long long sums = 0.0;
		for (int i : levelVals) {
			sums += (double) i;
		}
		result.push_back((double) sums / levelVals.size());
		return result;
	}
};
