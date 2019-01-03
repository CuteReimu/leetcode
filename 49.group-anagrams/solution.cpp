class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> cache;
		for (vector<string>::const_reference str : strs)
		{
			string s = str;
			sort(s.begin(), s.end());
			cache[s].push_back(str);
		}
		vector<vector<string>> result;
		for (map<string, vector<string>>::const_reference r : cache)
			result.push_back(r.second);
		return result;
	}
};
