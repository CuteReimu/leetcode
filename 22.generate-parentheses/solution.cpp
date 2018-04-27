class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		generateParenthesis(result, "", n, n);
		return result;
	}

private:
	void generateParenthesis(vector<string> &result, string temp, int l, int r)
	{
		if (r == 0)
		{
			result.push_back(temp);
			return;
		}
		if (l == 0)
		{
			string s;
			for (int i = 0; i < r; i++)
			{
				s += ')';
			}
			result.push_back(temp + s);
			return;
		}
		generateParenthesis(result, temp + "(", l - 1, r);
		if (l < r)
		{
			generateParenthesis(result, temp + ")", l, r - 1);
		}
	}
};
