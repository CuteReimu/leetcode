class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		if (n > 0)
		{
			vector<int> nums;
			for (int i = 0; i < n; i++)
				nums.push_back(i);
			vector<vector<int>> vec = permute(nums);
			for (vector<vector<int>>::const_reference v : vec)
			{
				result.emplace_back();
				for (vector<int>::const_reference i : v)
				{
					string s;
					for (int j = 0; j < n; j++)
						s += j == i ? 'Q' : '.';
					result.back().push_back(move(s));
				}
			}
		}
		return result;
	}

	vector<vector<int>> permute(vector<int>& nums) {
		list<vector<int>> result;
		if (!nums.empty())
		{
			result.push_back(vector<int>());
			int count = 0;
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
						if (nums.size() - 1 != count || check(vec))
								result.push_back(vec);
					}
					vector<int> vec(itr->begin(), itr->end());
					vec.push_back(*it);
					if (nums.size() - 1 != count || check(vec))
							result.push_back(vec);
					result.pop_front();
				}
				count++;
			}
		}
		return vector<vector<int>>(result.begin(), result.end());
	}

	bool check(const vector<int> &vec)
	{
		set<int> s;
		for (int i = 0; i < vec.size(); i++)
		{
			if (!s.insert(vec[i] - i).second)
				return false;
		}
		s.clear();
		for (int i = 0; i < vec.size(); i++)
		{
			if (!s.insert(vec[i] + i).second)
				return false;
		}
		return true;
	}
};
