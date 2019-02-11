class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> cache(wordList.begin(), wordList.end());
		if (cache.find(endWord) == cache.end()) return 0;
		cache.erase(beginWord);
		list<pair<int, string>> midStatus;
		midStatus.emplace_back(1, beginWord);
		while (!midStatus.empty())
		{
			pair<int, string> &p = midStatus.front();
			for (int i = 0; i < p.second.length(); i++)
			{
				string tmp = p.second;
				for (char c = 'a'; c <= 'z'; c++)
				{
					if (c == p.second[i]) continue;
					tmp[i] = c;
					if (cache.find(tmp) == cache.end()) continue;
					if (tmp == endWord) return p.first + 1;
					midStatus.emplace_back(p.first + 1, tmp);
					cache.erase(tmp);
				}
			}
			midStatus.pop_front();
		}
		return 0;
	}
};
