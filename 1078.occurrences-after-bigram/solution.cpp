class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
		string newStr = first + ' ' + second + ' ';
		int len = newStr.length();
		vector<string> result;
		int index = 0;
		while ((index = text.find(newStr, index)) != string::npos) {
			index += len;
			int indexspace = text.find(' ', index);
			if (indexspace == string::npos) {
				indexspace = text.length();
			}
			result.push_back(text.substr(index, indexspace - index));
		}
		return result;
    }
};
