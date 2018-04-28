class Solution {
public:
	int divide(int dividend, int divisor) {
		if (!dividend) return 0;
		int sign = dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0 ? 1 : -1;
		unsigned long d1 = dividend > 0 ? dividend : 0L - dividend;
		unsigned long d2 = divisor > 0 ? divisor : 0L - divisor;
		vector<pair<unsigned long, unsigned long>> cache;
		unsigned long l2 = 1;
		for (unsigned long l1 = d2; l1 <= d1; l1 += l1)
		{
			cache.emplace_back(l1, l2);
			l2 += l2;
		}
		unsigned long result = 0;
		for (auto it = cache.rbegin(); it != cache.rend(); it++)
		{
			if (d1 >= it->first)
			{
				d1 -= it->first;
				result += it->second;
			}
		}
		return sign > 0 ? result > INT_MAX ? INT_MAX : result : (long)result - 1 > INT_MAX ? INT_MIN : -(long)result;
	}
};
