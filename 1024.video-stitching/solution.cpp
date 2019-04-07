class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        if (T == 0) return 0;
		vector<vector<int>> cache1;
		for (int i = 0; i < clips.size(); i++) {
            const vector<int> &vec = clips[i];
			bool ret = true;
			for (int j = i + 1; j < clips.size(); j++) {
                const vector<int> &vec1 = clips[j];
				if (vec == vec1) {
					ret = false;
					break;
				}
			}
			if (ret)
				cache1.push_back(vec);
		}
        vector<vector<int>> cache;
        for (int i = 0; i < cache1.size(); i++) {
            const vector<int> &vec = cache1[i];
            bool ret = true;
            for (int j = 0; j < cache1.size(); j++) {
                if (j == i)
                    continue;
                const vector<int> &vec1 = cache1[j];
                if (vec[0] >= vec1[0] && vec[1] <= vec1[1] || vec[0] >= vec[1]) {
                    ret = false;
                    break;
                }
            }
            if (ret)
                cache.push_back(vec);
        }
        int count = 0;
        int last = 0;
        sort(cache.begin(), cache.end(), [](const vector<int> &vec, const vector<int> &vec1)->bool{return vec[0] < vec1[0];});
        for (int i = 0; i < cache.size(); i++) {
			if (i + 1 < cache.size() && cache[i + 1][0] <= last)
				continue;
			const vector<int> &vec = cache[i];
            if (vec[0] > last)
                return -1;
            last = vec[1];
            count++;
            if (last >= T)
                return count;
        }
        return -1;
    }
};
