class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> cache;
		for (int &i : nums)
			cache.emplace(i, 0);
		int maxLen = 0;
		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			int &i = cache[*it];
			if (i) continue;
			unordered_map<int, int>::iterator itr;
			int j = *it - 1;
			while (true)
			{
				itr = cache.find(j);
				if (itr == cache.end()) break;
				if (itr->second) break;
				j--;
			}
			int cur = itr == cache.end() ? 0 : itr->second;
			for (int k = j + 1; k <= *it; k++)
				cache[k] = ++cur;
			if (i > maxLen) maxLen = i;
		}
		return maxLen;
	}
};
