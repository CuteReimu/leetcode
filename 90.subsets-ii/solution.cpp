class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		unordered_map<int, int> cache;
		for (int &i : nums)
		{
			auto it = cache.find(i);
			if (it != cache.end())
				it->second++;
			else
				cache.emplace(i, 1);
		}
		int max = 1;
		for (pair<const int, int> &p : cache)
			max *= p.second + 1;
		vector<vector<int>> result;
		for (int i = 0; i < max; i++)
		{
			int a = i;
			result.emplace_back();
			vector<int> &vec = result.back();
			for (pair<const int, int> &p : cache)
			{
				int b = a % (p.second + 1);
				a /= p.second + 1;
				vec.resize(vec.size() + b, p.first);
			}
		}
		return result;
	}
};
