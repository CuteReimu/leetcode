class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> nums1cache;
		for (int i : nums1) {
			auto r = nums1cache.insert(pair<int, int>(i, 0));
			r.first->second++;
		}
		vector<int> result;
		for (int i : nums2) {
            auto it = nums1cache.find(i);
			if (it != nums1cache.end() && it->second) {
				result.push_back(i);
                it->second--;
			}
		}
		return result;
	}
};
