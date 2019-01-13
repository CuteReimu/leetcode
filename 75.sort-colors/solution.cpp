class Solution {
public:
	void sortColors(vector<int>& nums) {
		int beg, end, len = nums.size();
		for (beg = 0; beg < len && nums[beg] == '0'; beg++);
		if (beg == len) return;
		for (end = len - 1; end >= 0 && nums[end] == '2'; end--);
		for (int i = beg; i <= end;)
		{
			switch (nums[i])
			{
			case 0:
				nums[i] = nums[beg];
				nums[beg] = 0;
				for (; nums[beg] == 0; beg++);
				i = i < beg ? beg : i;
				break;
			case 1:
				i++;
				break;
			case 2:
				nums[i] = nums[end];
				nums[end] = 2;
				for (; nums[end] == 2; end--);
			}
		}
	}
};
