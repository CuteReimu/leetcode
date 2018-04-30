class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if (words.empty()) return result;
		multimap<string, int> cache;
		for (vector<string>::iterator it = words.begin(); it != words.end(); it++)
		{
			auto itr = cache.find(*it);
			if (itr == cache.end())
			{
				cache.emplace(*it, 1);
			} else
			{
				itr->second++;
			}
		}
		int count = 0;
		for (int i = 0; i + words.front().length() * words.size() <= s.length(); i++)
			if (check(s, i, cache, count, words.size())) result.push_back(i);
		return result;
	}
private:
	bool check(const string &s, int off, multimap<string, int> &cache, int count, const int &totalCount)
	{
		if (count == totalCount) return true;
		for (auto it = cache.begin(); it != cache.end(); it++)
		{
			if (it->second && startsWith(s, it->first, off))
			{
				it->second--;
				bool rtn = check(s, off + it->first.length(), cache, count + 1, totalCount);
				it->second++;
				if (rtn) return true;
			}
		}
		return false;
	}
	bool startsWith(const string &s, const string &sub, int off = 0)
	{
		if (s.length() - off < sub.length()) return false;
		for (int i = 0; i < sub.length(); i++)
			if (s[i+off] != sub[i]) return false;
		return true;
	}
};
