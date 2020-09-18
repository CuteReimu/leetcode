bool operator<(const vector<int> &v1, const vector<int> &v2) {
	for (int i = 0;;i++) {
		if (i == v2.size())
			return false;
		if (i == v1.size())
			return true;
		if (v1[i] != v2[i])
			return v1[i] < v2[i];
	}
}

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.size() == 0)
			return vector<vector<int>>();
		set<list<int>> result = permuteUnique(nums, 0);
		vector<vector<int>> result2;
		for (auto &l : result) {
			result2.emplace_back(l.begin(), l.end());
		}
		return result2;
	}

private:
	set<list<int>> permuteUnique(const vector<int>&nums, int i) {
		set<list<int>> result;
		if (nums.size() == i) {
			result.emplace();
			return result;
		}
		set<list<int>> result2 = permuteUnique(nums, i+1);
		for (auto val : result2) {
			for (auto it = val.begin();; it++) {
				it = val.insert(it, nums[i]);
				result.insert(val);
				it = val.erase(it);
				if (it == val.end())
					break;
			}
		}
		return result;
	}
};
