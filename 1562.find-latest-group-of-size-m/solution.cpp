class Solution {
public:
	int findLatestStep(vector<int>& arr, int m) {
		map<int, int> cache_begin_end;
		map<int, int> cache_end_begin;
		vector<int> cache_len_cnt(arr.size() + 1, 0);
		int result = -1;
		for (int index = 0; index < arr.size(); index++) {
			int i = arr[index];
			auto it1 = cache_begin_end.find(i + 1);
			auto it2 = cache_end_begin.find(i - 1);
			if (it1 == cache_begin_end.end()) {
				if (it2 == cache_end_begin.end()) {
					cache_len_cnt[1]++;
					cache_end_begin[i] = i;
					cache_begin_end[i] = i;
				} else {
					int b = it2->second;
					cache_end_begin.erase(it2);
					cache_begin_end[b] = i;
					cache_end_begin[i] = b;
					cache_len_cnt[i - b]--;
					cache_len_cnt[i - b + 1]++;
				}
			} else {
				if (it2 == cache_end_begin.end()) {
					int e = it1->second;
					cache_begin_end.erase(it1);
					cache_end_begin[e] = i;
					cache_begin_end[i] = e;
					cache_len_cnt[e - i]--;
					cache_len_cnt[e - i + 1]++;
				} else {
					int b = it2->second;
					int e = it1->second;
					cache_begin_end.erase(it1);
					cache_end_begin.erase(it2);
					cache_begin_end[b] = e;
					cache_end_begin[e] = b;
					cache_len_cnt[i - b]--;
					cache_len_cnt[e - i]--;
					cache_len_cnt[e - b + 1]++;
				}
			}
			if (cache_len_cnt[m] > 0)
				result = index + 1;
		}
		return result;
	}
};
