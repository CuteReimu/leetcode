class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		unordered_map<int, vector<vector<int>>> cache;
		sort(candidates.begin(), candidates.end());
		return combinationSum(cache, candidates, target);
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
