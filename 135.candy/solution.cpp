class Solution {
public:
	int candy(vector<int>& ratings) {
		int len = ratings.size();
		vector<int> vec(len, 0);
		map<int, vector<int>> cache;
		for (int i = 0; i < len; i++) {
			cache[ratings[i]].push_back(i);
		}
		for (pair<const int, vector<int>> &p : cache) {
			for (int &i : p.second) {
				vec[i] = 1;
				if (i > 0 && vec[i - 1] > 0 && !binary_search(p.second.begin(), p.second.end(), i - 1)) {
					vec[i] = max(vec[i - 1] + 1, vec[i]);
				}
				if (i + 1 < len && vec[i + 1] > 0 && !binary_search(p.second.begin(), p.second.end(), i + 1)) {
					vec[i] = max(vec[i + 1] + 1, vec[i]);
				}
			}
		}
		int sum = 0;
		for (int &i : vec) {
			sum += i;
		}
		return sum;
	}
};
