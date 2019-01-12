class Solution {
public:
	bool isNumber(string s) {
		int beg = -1;
		while(++beg < s.length() && s[beg] == ' ');
		if (beg == s.length()) return false;
		int end = s.length();
		while(s[--end] == ' ');
		s = s.substr(beg, end - beg + 1);
		if (s.length() == 0) return false;
		int eIndex = s.find('e');
		if (eIndex != string::npos)
		{
			if (s.find('e', eIndex + 1) != string::npos) return false;
			if (eIndex + 1 == s.length()) return false;
			if (s[eIndex + 1] == '-' || s[eIndex + 1] == '+'){
				if (eIndex + 2 == s.length()) return false;
				eIndex++;
			}
			for (int i = eIndex + 1; i < s.length(); i++)
				if (s[i] < '0' || s[i] > '9') return false;
			if (s[eIndex] == '-' || s[eIndex] == '+') eIndex--;
		}
		if (eIndex == string::npos) eIndex = s.length();
		int nStart = s[0] == '-' || s[0] == '+' ? 1 : 0;
		if (nStart == eIndex) return false;
		if (eIndex == nStart + 1 && (s[nStart] == '.' || s[nStart] == '-' || s[nStart] == '+')) return false;
		bool foundPoint = false;
		for (int i = nStart; i < eIndex; i++)
		{
			if (s[i] == '.')
			{
				if (foundPoint) return false;
				foundPoint = true;
			}
			else if (s[i] < '0' || s[i] > '9') return false;
		}
		return true;
	}
};
