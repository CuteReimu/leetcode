class Solution {
public:
	string getPermutation(int n, int k) {
		set<int> cache;
		string s;
		int c = 1;
		for (int i = 1; i <= n; i++)
		{
			cache.insert(i);
			c *= i;
		}
		for (int i = n - 1; i > 0; i--)
		{
			c /= i + 1;
			int y = (k - 1) / c;
			set<int>::iterator it = next(cache.begin(), y);
			k -= y * c;
			s += (char)('0' + *it);
			cache.erase(it);
		}
		s += '0' + *cache.begin();
		return s;
	}
};
