class Solution {
public:
	int numDistinct(string s, string t) {
        int len = s.length();
        int tlen = t.length();
        if (tlen == 0 || len == 0 || len < tlen) return 0;
        int *cache = new int[tlen];
        memset(cache, 0, tlen * sizeof(int));
        if (s[0] == t[0]) cache[0] = 1;
        for (int i = 1; i < len; i++)
        {
            for (int j = tlen - 1; j > 0; j--)
                if (s[i] == t[j])
                    cache[j] += cache[j - 1];
			if (s[i] == t[0])
				cache[0]++;
        }
        int result = cache[tlen - 1];
        delete[] cache;
        return result;
	}
};
