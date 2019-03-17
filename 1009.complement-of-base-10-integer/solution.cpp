class Solution {
public:
	int bitwiseComplement(int N) {
        if (N == 0) return 1;
		int len = 0, n = N;
		while (n != 0) {
			len++;
			n >>= 1;
		}
		return ~N & ((1 << len) - 1);
	}
};
