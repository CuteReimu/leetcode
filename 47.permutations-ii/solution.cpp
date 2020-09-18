class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.size() == 0)
			return vector<vector<int>>();
		vector<vector<int>> v1, v2;
		vector<vector<int>> *result = &v1, *another = &v2;
		v1.emplace_back();
		for (int num : nums) {
			for (auto it = result->begin(); it != result->end(); it++) {
				for (int j = 0;; j++) {
					another->push_back(*it);
					another->back().insert(another->back().begin() + j, num);
					if (j >= it->size() || (*it)[j] == num)
						break;
				}
			}
			result->clear();
			auto temp = result;
			result = another;
			another = temp;
		}
		return *result;
	}
};
