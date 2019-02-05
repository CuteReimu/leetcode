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
	vector<TreeNode*> generateTrees(int n) {
		unordered_map<int, vector<TreeNode *>> cache;
		return generateTrees(cache, n, 1);
	}
private:
	vector<TreeNode *> generateTrees(unordered_map<int, vector<TreeNode *>> &cache, int n, int start)
	{
		if (n == 0) return vector<TreeNode *>();
		if (n == 1) return vector<TreeNode *>(1, new TreeNode(start));
		auto it = cache.find(n);
		if (it != cache.end())
		{
			vector<TreeNode *> vec = clone(it->second);
			for (TreeNode *head : vec)
				add(head, start);
			return vec;
		}
		vector<TreeNode *> vec;
		vector<TreeNode *> vec0 = generateTrees(cache, n - 1, 1);
		for (TreeNode *head : vec0)
		{
			vec.push_back(new TreeNode(n));
			vec.back()->left = head;
		}
		vec0 = generateTrees(cache, n - 1, 2);
		for (TreeNode *head : vec0)
		{
			vec.push_back(new TreeNode(1));
			vec.back()->right = head;
		}
		for (int i = 2; i < n; i++)
		{
			vector<TreeNode *> vec1 = generateTrees(cache, i - 1, 1);
			vector<TreeNode *> vec2 = generateTrees(cache, n - i, i + 1);
			for (TreeNode *head1 : vec1)
			{
				for (TreeNode *head2 : vec2)
				{
					vec.push_back(new TreeNode(i));
					vec.back()->left = head1;
					vec.back()->right = head2;
				}
			}
		}
		cache.emplace(n, vec);
		vec = clone(vec);
		for (TreeNode *head : vec)
			add(head, start);
		return vec;
	}

	void add(TreeNode *head, int addition)
	{
		if (addition == 1 || !head) return;
		head->val += addition - 1;
		add(head->left, addition);
		add(head->right, addition);
	}

	vector<TreeNode *> clone(vector<TreeNode *> vec)
	{
		vector<TreeNode *> result;
		for (TreeNode *p : vec)
			result.push_back(clone(p));
		return result;
	}

	TreeNode *clone(TreeNode *head)
	{
		if (!head) return nullptr;
		TreeNode *head2 = new TreeNode(head->val);
		head2->left = clone(head->left);
		head2->right = clone(head->right);
		return head2;
	}
};
