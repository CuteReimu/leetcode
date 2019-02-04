class Solution {
public:
	int numDecodings(string s) {
		if (s.empty()) return 1;
		if (s[0] == '0') return 0;
		if (s.length() == 1) return 1;
		int *p = new int[s.length()];
		memset(p, 0, s.length() * sizeof(int));
		p[0] = 1;
		p[1] = p[0] * (s[1] == '0' ? 0 : 1) + (s[0] == '1' || (s[0] == '2' && s[1] <= '6') ? 1 : 0);
		for (int i = 2; i < s.length(); i++)
		{
			p[i] = p[i - 1] * (s[i] == '0' ? 0 : 1) + p[i - 2] * (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6') ? 1 : 0);
			if (p[i] == 0 && p[i - 1] == 0)
			{
				delete[] p;
				return 0;
			}
		}
		int result = p[s.length() - 1];
		delete[] p;
		return result;
	}
};
