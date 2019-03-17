class Solution {
public:
	int numPairsDivisibleBy60(vector<int>& time) {
		int cache[60] = {0};
		for (const int &i : time) {
			cache[i % 60]++;
		}
		int count = 0;
		for (const int &i : time) {
			cache[i % 60]--;
			count += cache[(60 - i % 60) % 60];
		}
		return count;
	}
};
