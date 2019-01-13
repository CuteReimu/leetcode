class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> vec(word1.length() + 1, vector<int>(word2.length() + 1, 0));
		for (int i = 1; i <= word1.length(); i++) vec[i][0] = i;
		for (int i = 1; i <= word2.length(); i++) vec[0][i] = i;
		for (int i = 1; i <= word1.length(); i++)
		{
			for (int j = 1; j <= word2.length(); j++)
			{
                if (word1[i - 1] == word2[j - 1]) vec[i][j] = vec[i - 1][j - 1];
                else {
                    int min = vec[i - 1][j - 1];
                    min = vec[i - 1][j] < min ? vec[i - 1][j] : min;
                    vec[i][j] = 1 + (vec[i][j - 1] < min ? vec[i][j - 1] : min);
                }
			}
		}
		return vec[word1.length()][word2.length()];
	}
};
