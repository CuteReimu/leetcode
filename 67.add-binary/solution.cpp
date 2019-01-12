class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		int next = 0;
		string::reverse_iterator ita = a.rbegin();
		string::reverse_iterator itb = b.rbegin();
		while (true)
		{
			int sum = next;
			if (ita != a.rend())
			{
				sum += *ita == '0' ? 0 : 1;
				ita++;
			}
			if (itb != b.rend())
			{
				sum += *itb == '0' ? 0 : 1;
				itb++;
			}
			next = sum >> 1;
			result += (char)('0' + (sum & 1));
			if (ita == a.rend() && itb == b.rend())
			{
				if (next) result += '1';
				break;
			}
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
