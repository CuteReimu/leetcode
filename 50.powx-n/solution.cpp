class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
		{
			return 1.0;
		} else if (n == INT_MIN)
		{
			double y = myPow(x, 0x40000000);
			return 1.0 / y / y;
		} else if (n < 0)
		{
			return 1 / myPow(x, -n);
		}
		double ans = 1.0;
		for (int i = n; i != 0; i >>= 1)
		{
			if (i & 1)
			{
				ans *= x;
			}
			x *= x;
		}
		return ans;
	}
};
