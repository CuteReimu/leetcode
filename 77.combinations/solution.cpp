class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> vec;
		combine(result, vec, n, k, 1);
		return result;
	}
private:
	void combine(vector<vector<int>> &result, vector<int> &cur, int n, int k, int start)
	{
		cur.emplace_back();
		if (1 == k)
		{
			for (int i = start; i <= n; i++)
			{
				cur.back() = i;
				result.push_back(cur);
			}
			cur.pop_back();
			return;
		}
		int len = n - k + 1;
		for (int i = start; i <= len; i++)
		{
			cur.back() = i;
			combine(result, cur, n, k - 1, i + 1);
		}
		cur.pop_back();
	}
};
