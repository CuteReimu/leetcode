class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		int result['z' + 1] = {0};
		for (int i = 0; i < A[0].size(); i++) {
			result[A[0][i]]++;
		}
		for (int i = 1; i < A.size(); i++) {
			int result2['z' + 1] = {0};
			for (int j = 0; j < A[i].size(); j++) {
				result2[A[i][j]]++;
			}
			for (char j = 'a'; j <= 'z'; j++) {
				result[j] = min(result[j], result2[j]);
			}
		}
		vector<string> vec;
		for (char c = 'a'; c <= 'z'; c++) {
			for (int i = 0; i < result[c]; i++)
				vec.emplace_back(1, c);
		}
		return vec;
	}
};
