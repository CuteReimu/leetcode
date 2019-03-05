class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> cache(numCourses, vector<int>());
		for (pair<int, int> &p : prerequisites) {
			cache[p.first].push_back(p.second);
		}
		vector<unsigned char> pointstatus(numCourses, 0);
		for (int i = 0; i < numCourses; i++) {
			if (!dfs(cache, pointstatus, i)) return false;
		}
		return true;
	}

	bool dfs(const vector<vector<int>> &cache, vector<unsigned char> &pointstatus, int i) {
		if (pointstatus[i] != 0) return pointstatus[i] == 2;
		pointstatus[i] = 1;
		for (int j = 0; j < cache[i].size(); j++) {
			if (!dfs(cache, pointstatus, cache[i][j]))
				return false;
		}
		pointstatus[i] = 2;
		return true;
	}
};
