class Solution {
public:
	string countAndSay(int n) {
		string s = "1";
		for (int i = 1; i < n; i++)
		{
			stringstream ss;
			char last = '.';
			int cnt = 0;
			for (char c : s)
			{
				if (last != c)
				{
					if (last != '.')
						ss << cnt << last;
					last = c;
					cnt = 1;
				} else
				{
					cnt++;
				}
			}
			ss << cnt << last;
			s = ss.str();
		}
		return s;
	}
};
