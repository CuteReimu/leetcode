class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> cache(wordList.begin(), wordList.end());
		if (cache.find(endWord) == cache.end()) return vector<vector<string>>();
		cache.erase(beginWord);
		list<pair<int, pair<string, vector<string>>>> midStatus;
		midStatus.emplace_back(1, make_pair(beginWord, vector<string>(1, beginWord)));
		vector<string> removeCache;
		int curDeep = 1;
		while (!midStatus.empty())
		{
			pair<int, pair<string, vector<string>>> &p = midStatus.front();
			if (p.first > curDeep)
			{
				for (const string &s : removeCache)
					cache.erase(s);
				removeCache.clear();
				curDeep = p.first;
			}
			if (p.second.first == endWord) {
				vector<vector<string>> result;
				for (auto &p1 : midStatus) {
					if (p1.first > p.first) break;
					if (p1.second.first == endWord)
						result.push_back(p1.second.second);
				}
				return result;
			}
			for (int i = 0; i < p.second.first.length(); i++)
			{
				string tmp = p.second.first;
				for (char c = 'a'; c <= 'z'; c++)
				{
					if (c == p.second.first[i]) continue;
					tmp[i] = c;
					if (cache.find(tmp) == cache.end()) continue;
					midStatus.emplace_back(p.first + 1, make_pair(tmp, p.second.second));
					midStatus.back().second.second.push_back(tmp);
					removeCache.push_back(tmp);
				}
			}
			midStatus.pop_front();
		}
		return vector<vector<string>>();
	}
};
