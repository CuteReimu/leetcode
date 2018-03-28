class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		if (nums.empty())
			return ans;
		int *p = &*nums.begin();
		sort(nums.begin(), nums.end());
		int len = nums.size();
		for (int i = 0; i < len && nums[i] <= 0; i++)
		{
			if(i > 0 && nums[i] == nums[i - 1])
				continue;
			int j = i + 1;
			int k = len - 1;
			while (j < k)
			{
				int result = nums[i] + nums[j] + nums[k];
				if (result == 0)
				{
					int arr[] = {nums[i], nums[j], nums[k]};
					ans.emplace_back(arr, arr + 3);
					while(j + 1 < nums.size() && nums[j+1]==nums[j]) j++;
					while(k - 1 > i && nums[k-1]==nums[k]) k--;
					j++;
					k--;
				} else if (result > 0)
					k--;
				else
					j++;
			}
		}
		return ans;
	}
};
