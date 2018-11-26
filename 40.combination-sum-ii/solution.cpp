class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		map<int, int> s;
		for (int & i : candidates)
		{
			map<int, int>::iterator it = s.find(i);
			if (it == s.end())
			{
				s.emplace(i, 1);
			} else
			{
				it->second++;
			}
		}
		candidates.clear();
		for (pair<int, int> p : s)
		{
			candidates.push_back(p.first);
		}
		unordered_map<int, vector<vector<int>>> cache;
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result = combinationSum(cache, candidates, target);
		vector<vector<int>> result2;
		for (vector<vector<int>>::iterator it = result.begin(); it != result.end(); it++)
		{
			int last = 0;
			int count = 0;
			bool correct = true;
			for (int &ii : *it)
			{
				if (last != ii)
				{
					last = ii;
					count = 1;
				} else if (++count > s[ii])
				{
					correct = false;
					break;
				}
			}
			if (correct)
				result2.push_back(*it);
		}
		return result2;
	}
private:
	vector<vector<int>> combinationSum(unordered_map<int, vector<vector<int>>> &cache, vector<int>& candidates, int target)
	{
		if (target <= 0)
			return vector<vector<int>>();
		unordered_map<int, vector<vector<int>>>::iterator it = cache.find(target);
		if (it != cache.end())
			return it->second;
		vector<vector<int>> result;
		for (int &i : candidates)
		{
			if (i == target)
			{
				result.emplace_back();
				result.back().push_back(target);
			}
		}
		for (int &i : candidates)
		{
			vector<vector<int>> vec2 = combinationSum(cache, candidates, target - i);
			for (vector<int> &v2 : vec2)
			{
				vector<int> vv;
				vv.push_back(i);
				vv.insert(vv.end(), v2.begin(), v2.end());
				sort(vv.begin(), vv.end());
				bool found = false;
				for (vector<vector<int>>::const_iterator itr = result.begin(); itr != result.end(); itr++)
				{
					if (*itr == vv)
					{
						found = true;
						break;
					}
				}
				if (!found)
					result.emplace_back(vv);
			}
		}
		cache.insert(make_pair(target, result));
		return result;
	}
};
