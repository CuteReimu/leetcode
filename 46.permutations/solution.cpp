class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		list<vector<int>> result;
		if (!nums.empty())
		{
			result.push_back(vector<int>());
			for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
			{
				int i = 0;
				int iMax = result.size();
				for (int i = 0; i < iMax; i++)
				{
					list<vector<int>>::iterator itr = result.begin();
					for (vector<int>::iterator iter = itr->begin(); iter != itr->end(); iter++)
					{
						vector<int> vec(itr->begin(), iter);
						vec.push_back(*it);
						vec.insert(vec.end(), iter, itr->end());
						result.push_back(vec);
					}
					vector<int> vec(itr->begin(), itr->end());
					vec.push_back(*it);
					result.push_back(vec);
					result.pop_front();
				}
			}
		}
		return vector<vector<int>>(result.begin(), result.end());
	}
};
