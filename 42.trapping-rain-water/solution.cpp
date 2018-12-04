class Solution {
public:
	int trap(vector<int>& height) {
		int sum = 0;
		int maxvalue = -1;
		int maxindex = -1;
		for (int i = 0; i < height.size(); i++)
		{
			if (height[i] > maxvalue)
			{
				maxvalue = height[i];
				maxindex = i;
			}
			sum += height[i];
		}
		if (maxvalue <= 0)
			return 0;
		int sum2 = 0;
		int lastvalue = 0;
		for (int i = 0; i < maxindex; i++)
		{
			if (height[i] > lastvalue)
				lastvalue = height[i];
			sum2 += lastvalue;
		}
		sum2 += maxvalue;
		lastvalue = 0;
		for (int i = height.size() - 1; i > maxindex; i--)
		{
			if (height[i] > lastvalue)
				lastvalue = height[i];
			sum2 += lastvalue;
		}
		return sum2 - sum;
	}
};
