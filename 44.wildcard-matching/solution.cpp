class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
			return s.empty();
		vector<string> vecString;
		if (p[0] == '*')
			vecString.push_back("");
		string ss;
		for (int i = 0; i < p.length(); i++)
		{
			if (p[i] == '*')
			{
				if (!ss.empty())
				{
					vecString.push_back(ss);
					ss.clear();
				}
				continue;
			}
			ss += p[i];
		}
		vecString.push_back(ss);
		if (vecString.size() == 1)
		{
			return s.length() == p.length() && equals(s, p);
		}
		int idx = 0;
		if (!vecString[0].empty())
		{
			if (!startswith(s, vecString[0]))
				return false;
			idx = vecString[0].length();
		}
		for (int i = 1; i < vecString.size() - 1; i++)
		{
			idx = find(s, vecString[i], idx);
			if (idx == string::npos)
				return false;
			idx += vecString[i].length();
		}
		if (idx == s.length())
		{
			return vecString[vecString.size() - 1].empty();
		}
		const string &backString = vecString.back();
		if (!backString.empty())
		{
			if (idx + backString.length() > s.length() || !endswith(s, backString))
				return false;
		}
		return true;
	}
private:
	string::size_type find(const string &s1, const string &s2, int off = 0)
	{
		if (s1.length() - off < s2.length())
			return string::npos;
		for (int i = off; i < s1.length(); i++)
		{
			if (equals(s1, s2, i))
				return i;
		}
		return string::npos;
	}
	
	bool startswith(const string &s1, const string &s2)
	{
		if (s1.length() < s2.length())
			return false;
		return equals(s1, s2);
	}

	bool endswith(const string &s1, const string &s2)
	{
		if (s1.length() < s2.length())
			return false;
		return equals(s1, s2, s1.length() - s2.length());
	}

	bool equals(const string &s1, const string &s2, int off = 0)
	{
		if (s1.length() - off < s2.length())
			return false;
		for (int i = 0; i < s2.length(); i++)
		{
			if (s2[i] != '?' && s1[off + i] != s2[i])
				return false;
		}
		return true;
	}
};
