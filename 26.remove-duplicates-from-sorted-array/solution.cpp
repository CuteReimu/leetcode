class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int result = 1;
		vector<int>::iterator cur = nums.begin();
		for (vector<int>::const_iterator it = nums.begin() + 1; it != nums.end(); it++)
		{
			if (*cur != *it)
			{
				result++;
				*(++cur) = *it;
			}
		}
		return result;
	}
};
