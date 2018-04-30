class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		bool checkLast = true;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i - 1] < nums[i])
			{
				checkLast = false;
				break;
			}
		}
		if (checkLast)
		{
			reverse(nums.begin(), nums.end());
			return;
		}
		for (int j = nums.size() - 2; j >= 0; j--)
		{
			for (int i = nums.size() - 1; i > j; i--)
			{
				if (nums[i] > nums[j])
				{
					auto it = nums.begin();
					advance(it, j);
					swap(*it, *(it + (i - j)));
					reverse(++it, nums.end());
					return;
				}
			}
		}
    }
};
