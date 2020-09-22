class Solution {
public:
	int minCameraCover(TreeNode* root) {
		if (!root) return 0;
		return minResult(minCameraCover(root, -1), minCameraCover(root, 1));
	}
private:
	inline int minResult(int r1, int r2) {
		if (r1 == -1) return r2;
		if (r2 == -1) return r1;
		return min(r1, r2);
	}
	inline int minResult(int r1, int r2, int r3) {
		if (r1 == -1) return minResult(r2, r3);
		if (r2 == -1) return minResult(r1, r3);
		if (r3 == -1) return minResult(r1, r2);
		return min(r1, min(r2, r3));
	}
	inline int addResult(int r1, int r2) {
		if (r1 == -1 || r2 == -1) return -1;
		return r1 + r2;
	}
	map<pair<TreeNode *, int>, int> cache;
	int minCameraCover(TreeNode* root, int status) { // 0 - 根节点没被覆盖 -1 - 根节点被覆盖了 1 - 根节点上有
		if (!root->left && !root->right)
			return status;
		auto it = cache.find(make_pair(root, status));
		if (it != cache.end())
			return it->second;
		int result;
		if (root->left && root->right) {
			switch (status) {
			case 0:
				result = addResult(minCameraCover(root->left, -1), minCameraCover(root->right, -1));
				break;
			case 1: {
				int resultLeft = minResult(minCameraCover(root->left, -1), minCameraCover(root->left, 0), minCameraCover(root->left, 1));
				int resultRight = minResult(minCameraCover(root->right, -1), minCameraCover(root->right, 0), minCameraCover(root->right, 1));
				result = addResult(addResult(resultLeft, resultRight), 1);
				break;
					}
			case -1: {
				int resultLeft1 = minCameraCover(root->left, 1);
				int resultRight1 = minCameraCover(root->right, 1);
				int resultLeft_1 = minCameraCover(root->left, -1);
				int resultRight_1 = minCameraCover(root->right, -1);
				result = minResult(
					addResult(resultLeft1, resultRight1),
					addResult(resultLeft1, resultRight_1),
					addResult(resultLeft_1, resultRight1)
					);
					 }
			}
		} else {
			TreeNode *next = root->left ? root->left : root->right;
			switch (status) {
			case 0:
				result = minCameraCover(next, -1);
				break;
			case 1:
				result = addResult(minResult(minCameraCover(next, -1), minCameraCover(next, 0)), 1);
				break;
			case -1:
				result = minCameraCover(next, 1);
			}
		}
		cache.insert(make_pair(make_pair(root, status), result));
		return result;
	}
};
