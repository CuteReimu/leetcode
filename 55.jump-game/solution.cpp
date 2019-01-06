class Solution {
public:
	bool canJump(vector<int>& nums) {
		bool found = true;
		int last = nums.size() - 2;
        int len;
		for (int i = last; i >= 0; i--)
		{
			if (found && !nums[i] && (i == last || nums[i + 1]))
			{
				found = false;
				len = 0;
			} else if (!found && ++len < nums[i])
				found = true;
		}
		return found;
	}
};
