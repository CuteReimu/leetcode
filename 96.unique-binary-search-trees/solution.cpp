class Solution {
public:
	int numTrees(int n) {
		unordered_map<int, int> cache;
		return numTrees(cache, n);
	}
private:
	int numTrees(unordered_map<int, int> &cache, int n)
	{
		if (n == 0 || n == 1) return 1;
		unordered_map<int, int>::iterator it = cache.find(n);
		if (it != cache.end()) return it->second;
		int num = 0;
		for (int i = 1; i <= n; i++)
			num += numTrees(cache, i - 1) * numTrees(cache, n - i);
		cache.emplace(n, num);
		return num;
	}
};
