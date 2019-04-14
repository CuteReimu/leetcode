class Solution {
public:
    bool divisorGame(int N) {
		cache.clear();
		return _divisorGame(N);
	}
private:
	bool _divisorGame(int N) {
		auto it = cache.find(N);
		if (it != cache.end()) return it->second;
		vector<int> vec;
        for (int i = 1; i < N; i++) {
			if (N % i == 0)
				vec.push_back(i);
		}
		if (vec.empty()) return false;
		for (int i : vec) {
			if (!_divisorGame(N - i)) {
				cache.emplace(N, true);
				return true;
			}
		}
		cache.emplace(N, false);
		return false;
    }
private:
	map<int, bool> cache;
};
