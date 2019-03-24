class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ii = A[0] + 0;
        int j = 1;
        int maxVal = 0;
        while (j < A.size()) {
            int val = ii + A[j] - j;
            maxVal = max(maxVal, val);
            ii = max(ii, A[j] + j);
            j++;
        }
        return maxVal;
    }
};
