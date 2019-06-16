class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int, int>> vec(values.size());
        for (int i = 0; i < vec.size(); i++) {
            vec[i].first = values[i];
            vec[i].second = labels[i];
        }
		sort(vec.begin(), vec.end(), [&](const pair<int, int> &p1, const pair<int, int> &p2)->bool{
			return p1.first > p2.first || p1.first == p2.first && p1.second < p2.second;
		});
		unordered_map<int, int> cache;
		int count = 0;
		int result = 0;
		for (const pair<int, int> &p : vec) {
			if (++cache.emplace(p.second, 0).first->second <= use_limit) {
				result += p.first;
				if (++count >= num_wanted) break;
			}
		}
		return result;
    }
};
