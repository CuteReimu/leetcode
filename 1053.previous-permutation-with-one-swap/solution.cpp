class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        map<int, int> cache;
		for (int i = A.size() - 1; i >= 0; i--) {
			auto it = cache.emplace(A[i], i).first;
			if (it != cache.begin()) {
				advance(it, -1);
				swap(A[i], A[it->second]);
				return A;
			}
		}
		return A;
    }
};
