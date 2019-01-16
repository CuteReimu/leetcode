class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int i = 0;
		int curValue;
		int curCount = 0;
		for (int &n : nums)
		{
			switch (curCount)
			{
			case 0:
				curCount = 1;
				curValue = n;
				i++;
				break;
			case 1:
				curCount = curValue == n ? 2 : 1;
				curValue = n;
				nums[i++] = n;
				break;
			case 2:
				if (curValue != n)
				{
					curCount = 1;
					curValue = n;
					nums[i++] = n;
				}
			}
		}
		return i;
	}
};
