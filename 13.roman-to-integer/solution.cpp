class Solution {
public:
    int romanToInt(string s) {
		static int r2i[] = {0, 0, 100, 500, 0, 0, 0, 0, 1, 0, 0, 50, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10, 0, 0};
		int ans = 0;
		int len = s.length();
		int c;
		int c2 = r2i[s[0] - 'A'];
		for (int i = 0; i < len; i++)
		{
			c = c2;
			if (i == len - 1)
			{
				ans += c;
			} else
			{
				c2 = r2i[s[i + 1] - 'A'];
				if (c < c2)
					ans -= c;
				else
					ans += c;
			}
		}
		return ans;
    }
};
