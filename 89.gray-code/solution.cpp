class Solution {
public:
	vector<int> grayCode(int n) {
		if (n == 0)
			return vector<int>(1, 0);
		vector<int> result(1 << n);
		result[0] = 0;
		result[1] = 1;
		if (n == 1)
			return result;
		for (int i = 2; i <= n; i++)
		{
			int end2 = 1 << i;
			int end1 = end2 >> 1;
			for (int i = end1; i < end2; i++)
				result[i] = end1 + result[end2 - i - 1];
		}
		return result;
	}
};
