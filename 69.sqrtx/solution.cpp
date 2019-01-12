class Solution {
public:
	int mySqrt(int x) {
		int arr[32], len = 0;
		while (x)
		{
			arr[len++] = x & 3;
			x >>= 2;
		}
		int val = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			int &a = arr[i];
			val <<= 1;
			if (val)
			{
				int tmp = a / (val << 1);
				int tmp2 = tmp * tmp + tmp * val * 2;
				if (tmp2 > a)
				{
					tmp--;
					tmp2 = tmp * tmp + tmp * val * 2;
				}
				a -= tmp2;
				val |= tmp;
			} else
			{
				val = 1;
				arr[i] -= 1;
			}
			if (i)
				arr[i - 1] |= a << 2;
		}
		return val;
	}
};
