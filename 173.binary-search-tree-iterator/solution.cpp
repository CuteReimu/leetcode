/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
		if (!root)
		{
			p = nullptr;
			return;
		}
		while (root->left) {
			cache.push(root);
			root = root->left;
		}
		p = root;
	}

	/** @return the next smallest number */
	int next() {
		int result = p->val;
		if (p->right) {
			p = p->right;
		} else {
			if (cache.empty())
				p = nullptr;
			else {
				p = cache.top();
				cache.pop();
			}
			return result;
		}
		while (p->left) {
			cache.push(p);
			p = p->left;
		}
		return result;
	}

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return p != nullptr;
    }
private:
    stack<TreeNode *> cache;
    TreeNode *p;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
