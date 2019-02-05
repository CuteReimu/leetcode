class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		len1 = s1.length();
		len2 = s2.length();
		len3 = s3.length();
		if (len3 != len1 + len2) return false;
		this->s1 = s1;
		this->s2 = s2;
		this->s3 = s3;
		cache.clear();
		return isInterleave(0, 0, 0);
	}
private:
	map<pair<int, int>, bool> cache;
	string s1;
	string s2;
	string s3;
	int len1;
	int len2;
	int len3;
	bool isInterleave(int idx1, int idx2, int idx3) {
		if (len1 == idx1 && len2 == idx2)
			return true;
		pair<int, int> key(idx1, idx2);
		auto it = cache.find(key);
		if (it != cache.end()) return it->second;
		bool answer;
		if (idx1 >= len1 || idx3 >= len3 || s1[idx1] != s3[idx3])
		{
			if (idx2 >= len2 || idx3 >= len3 || s2[idx2] != s3[idx3])
				return false;
			else
				answer = isInterleave(idx1, idx2 + 1, idx3 + 1);
		} else
		{
			if (idx2 >= len2 || idx3 >= len3 || s2[idx2] != s3[idx3])
				answer = isInterleave(idx1 + 1, idx2, idx3 + 1);
			else
				answer = isInterleave(idx1, idx2 + 1, idx3 + 1) || isInterleave(idx1 + 1, idx2, idx3 + 1);
		}
		cache.emplace(key, answer);
		return answer;
	}
};
