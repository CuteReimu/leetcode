class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1[0] == '0' || num2[0] == '0')
			return "0";
		string result;
		int next = 0;
		for (int i = 0; i < num1.size() + num2.size(); i++)
		{
			int value = next;
			for (int j = 0; j <= i; j++)
			{
				if (1 + j <= num1.size() && 1 + i - j <= num2.size())
					value += (num1[num1.size() - 1 - j] - '0') * (num2[num2.size() - 1 - i + j] - '0');
			}
			next = value / 10;
			result.insert(result.begin(), (char)(value % 10 + '0'));
		}
		if (result[0] == '0')
			result.erase(result.begin());
		return result;
	}
};
