class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int result = 0;
		vector<int>::iterator cur = nums.begin();
		for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); it++)
		{
			if (val != *it)
			{
				result++;
				*(cur++) = *it;
			}
		}
		return result;
	}
};
