class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for (string::iterator it = s.begin(); it != s.end(); it++)
		{
			char c = *it;
			if (c == '{' || c == '[' || c == '(')
				st.push(*it);
			else
			{
				if (st.empty())
					return false;
				char vl = c - st.top();
				if (vl != 1 && vl != 2)
					return false;
				st.pop();
			}
		}
		return st.empty();
	}
};
