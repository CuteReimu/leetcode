class Solution {
public:
	int jump(vector<int>& nums) {
		int *result = new int[nums.size()];
		memset(result, 0, nums.size() * sizeof(int));
		int p = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			for (;p <= i + nums[i] && p < nums.size(); p++)
				result[p] = result[i] + 1;
			if (p >= nums.size())
				break;
		}
		int ans = result[nums.size() - 1];
		delete[] result;
		return ans;
	}
};
