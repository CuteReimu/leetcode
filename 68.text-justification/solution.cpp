class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> result;
		int len = -1;
		int beg = 0;
		for (int i = 0; i < words.size(); i++)
		{
			len += 1 + words[i].length();
			if (len > maxWidth)
			{
				if (i - beg == 1)
				{
					result.push_back(words[beg]);
					result.back().resize(maxWidth, ' ');
				} else
				{
					len -= words[i].length() + 1;
					int spaceCount = i - beg - 1;
					int spaceDivision = (maxWidth - len) / spaceCount;
					int spaceRemain = (maxWidth - len) % spaceCount;
					string s;
					for (int j = beg; j < i; j++)
					{
						if (j != beg) s.append(j - beg <= spaceRemain ? spaceDivision + 2 : spaceDivision + 1, ' ');
						s += words[j];
					}
					result.push_back(std::move(s));
				}
				len = words[i].length();
				beg = i;
			}
		}
		string s;
		for (int j = beg; j < words.size(); j++)
		{
			if (j != beg) s += ' ';
			s += words[j];
		}
		s.resize(maxWidth, ' ');
		result.push_back(std::move(s));
		return result;
	}
};
