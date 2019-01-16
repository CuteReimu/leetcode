class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int curValue = nums[0];
		int len = nums.size();
		int i = len > 1 && nums[0] == nums[1] ? 1 : 0;
		for (int j = 1; j < len; j++)
		{
			if (nums[j] != curValue)
			{
				nums[i++] = curValue;
				curValue = nums[j];
				if (j + 1 < len && nums[j] == nums[j + 1]) nums[i++] = curValue;
			}
		}
		nums[i++] = curValue;
		return i;
	}
};
