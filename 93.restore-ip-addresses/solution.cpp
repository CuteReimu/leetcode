class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		int len = s.length();
		for (int i = 1; i <= 3 && i <= len; i++)
		{
			if (i > 1 && s[0] == '0') continue;
			if (i == 3 && (s[0] > '2' || s[0] == '2' && (s[1] > '5' || s[1] == '5' && s[2] > '5'))) continue; 
			for (int j = i + 1; j <= i + 3 && j <= len; j++)
			{
				if (j - i > 1 && s[i] == '0') continue;
				if (j - i == 3 && (s[i] > '2' || s[i] == '2' && (s[i + 1] > '5' || s[i + 1] == '5' && s[i + 2] > '5'))) continue; 
				for (int k = j + 1; k <= j + 3 && k < len; k++)
				{
					if (k + 3 < len) continue;
					if (k - j > 1 && s[j] == '0') continue;
					if (k - j == 3 && (s[j] > '2' || s[j] == '2' && (s[j + 1] > '5' || s[j + 1] == '5' && s[j + 2] > '5'))) continue; 
					if (len - k > 1 && s[k] == '0') continue;
					if (len - k == 3 && (s[k] > '2' || s[k] == '2' && (s[k + 1] > '5' || s[k + 1] == '5' && s[k + 2] > '5'))) continue;
					result.push_back(s);
					result.back().insert(k, 1, '.');
					result.back().insert(j, 1, '.');
					result.back().insert(i, 1, '.');
				}
			}
		}
		return result;
	}
};
