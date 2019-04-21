class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
		sort(costs.begin(), costs.end(), [](const vector<int> &v1, const vector<int> &v2)->bool{
			return v1[0] - v1[1] < v2[0] - v2[1];
		});
		int count = costs.size();
		int sum = 0;
		for (int i = 0; i < count / 2; i++) {
			sum += costs[i][0];
			sum += costs[i + count / 2][1];
		}
		return sum;
    }
};
