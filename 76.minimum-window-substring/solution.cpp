class Solution {
public:
	string minWindow(string s, string t) {
		int cache['z' + 1] = {0};
		int count = 0;
		for (int i = 0; i < t.length(); i++)
		{
			if (!cache[t[i]]++) count++;
		}
		int cache2['z' + 1] = {0};
		int beg = 0, end = 0;
		string result;
		while (true)
		{
			for (; end < s.length(); end++)
			{
				if (cache[s[end]] && ++cache2[s[end]] == cache[s[end]] && !--count)
					break;
			}
			if (end == s.length()) return result;
			for (; beg < s.length(); beg++)
			{
				if (cache[s[beg]] && --cache2[s[beg]] < cache[s[beg]])
				{
					count++;
					if (result.empty() || result.length() > end - beg + 1)
						result = s.substr(beg, end - beg + 1);
					beg++;
					end++;
					break;
				}
			}
		}
	}
};
