class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++)
		{
			int j = i;
			while (nums[j] < nums.size() && nums[j] > 0 && nums[j] != j + 1 && nums[j] != nums[nums[j] - 1])
			{
				int temp = nums[j];
				nums[j] = nums[temp - 1];
				nums[temp - 1] = temp;
			}
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != i + 1)
			{
				return i + 1;
			}
		}
		return nums.size() + 1;
	}
};
