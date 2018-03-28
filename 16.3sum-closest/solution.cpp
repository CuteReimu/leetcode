class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		int min = target > 0 ? INT_MAX : INT_MIN + 1;
		for (int i = 0; i < len; i++)
		{
			if (nums[i] > (target + 2) / 3)
			{
				if (i < len - 2)
					min = nearest(min, nums[i] + nums[i + 1] + nums[i + 2], target);
				break;
			}
			if(i > 0 && nums[i] == nums[i - 1])
				continue;
			int j = i + 1;
			int k = len - 1;
			while (j < k)
			{
				int result = nums[i] + nums[j] + nums[k];
				if (result == target)
					return target;
				min = nearest(min, nums[i] + nums[j] + nums[k], target);
				if (result > target)
					k--;
				else
					j++;

			}
		}
		return min;
	}

	inline int nearest(const int &a, const int &b, const int &target)
	{
		return abs(a - target) > abs(b - target) ? b : a;
	}
};
