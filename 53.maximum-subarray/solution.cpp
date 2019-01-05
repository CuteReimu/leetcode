class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		int maxresult = nums.front();
		int val = maxresult;
		bool inited = false;
		int max = val;
		int min = val;
		for (int i = 1; i < len; i++)
		{
			int &v = nums[i];
			inited = true;
			val += v;
			if (val < min)
			{
				min = val;
				max = val;
				inited = false;
				maxresult = v > maxresult ? v : maxresult;
			} else
				max = val > max ? val : max;
			int result = inited ? max - (min < 0 ? min : 0) : max;
			maxresult = result > maxresult ? result : maxresult;
		}
		return maxresult;
	}
};
