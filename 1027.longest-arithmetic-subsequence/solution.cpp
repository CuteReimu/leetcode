class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int len = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = i + 1; j < A.size(); j++) {
                int diff = A[j] - A[i];
                int next = A[j] + diff;
                int index = j + 1;
                int len2 = 2;
                while (index < A.size()) {
                    if (A[index++] == next) {
                        len2++;
                        next += diff;
                    }
                }
                len = max(len, len2);
            }
        }
        return len;
    }
};
