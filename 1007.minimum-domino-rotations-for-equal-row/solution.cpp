class Solution {
public:
	int minDominoRotations(vector<int>& A, vector<int>& B) {
		int len = A.size();
		int num[6] = {0}, Anum[6] = {0}, Bnum[6] = {0};
		for (int i = 0; i < len; i++)
		{
			num[A[i] - 1]++;
			Anum[A[i] - 1]++;
			if (B[i] != A[i]) num[B[i] - 1]++;
			Bnum[B[i] - 1]++;
		}
		int can[6];
		for (int i = 0; i < 6; i++)
			can[i] = num[i] < len ? 0 : 1;
		int result = -1;
		for (int i = 0; i < 6; i++) {
			if (num[i] >= len) {
				int tmp = min(len - Anum[i], len - Bnum[i]);
				if (result == -1) result = tmp;
				else result = min(result, tmp);
			}
		}
		return result;
	}
};
