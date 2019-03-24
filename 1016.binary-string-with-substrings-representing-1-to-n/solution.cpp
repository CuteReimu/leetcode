class Solution {
public:
    bool queryString(string S, int N) {
        for (int i = N / 2 + 1; i <= N; i++) {
            string s;
            int ii = i;
            while (ii > 0) {
                s = (ii & 1) == 0 ? "0" + s : "1" + s;
                ii >>= 1;
            }
            if (S.find(s) == string::npos) return false;
        }
        return true;
    }
};
