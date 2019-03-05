class Solution {
public:
	int mergeStones(vector<int>& stones, int K) {
		vector<vector<int>> cache(stones.size() + 1, vector<int>(stones.size() + 1, 0));
		return mergeStones(cache, stones, K, 0, stones.size());
	}
private:
	int mergeStones(vector<vector<int>> &cache, const vector<int>& stones, int k, int i, int j) {
		if (i >= j) return -1;
		if ((j - i - 1) % (k - 1) != 0) return -1;
		if (j == i + 1) return 0;
		if (cache[i][j] != 0) return cache[i][j];
		int result = mergeKStones(cache, stones, k, i, j, k);
		return cache[i][j] = result == -1 ? -1 : result + sum(stones, i, j);
	}
	int mergeKStones(vector<vector<int>> &cache, const vector<int>& stones, int K, int i, int j, int k) {
		if (K == 1) return i + 1 == j ? 0 : -1;
		if (k == 1) return mergeStones(cache, stones, K, i, j);
		int result = INT_MAX;
		for (int x = i + 1; x < j; x++) {
			int val1 = mergeStones(cache, stones, K, i, x);
			if (val1 != -1) {
				int val2 = mergeKStones(cache, stones, K, x, j, k - 1);
				if (val2 != -1) {
					result = min(result, val1 + val2);
				}
			}
		}
		return result == INT_MAX ? -1 : result;
	}
	int sum(const vector<int>& stones, int i, int j) {
		int s = 0;
		for (int x = i; x < j; x++)
			s += stones[x];
		return s;
	}
};
