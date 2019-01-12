class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> result = digits;
		++result.back();
		for (vector<int>::reverse_iterator it = result.rbegin(); it != result.rend(); it++)
		{
			if (*it == 10)
			{
				vector<int>::reverse_iterator itnext = it + 1;
				if (itnext != result.rend())
				{
					*it = 0;
					++*itnext;
				} else
				{
					*it = 0;
					result.insert(result.begin(), 1);
					break;
				}
			}
		}
		return result;
	}
};
