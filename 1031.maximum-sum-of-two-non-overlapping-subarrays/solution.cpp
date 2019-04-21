class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int maxSum = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                if (i + L - 1 < j && j + M - 1 < A.size() || j + M - 1 < i && i + L - 1 < A.size()) {
                    int sum = 0;
                    for (int x = i; x <= i + L - 1; x++) {
                        sum += A[x];
                    }
                    for (int x = j; x <= j + M - 1; x++) {
                        sum += A[x];
                    }
                    maxSum = max(maxSum, sum);
                }
            }
        }
        return maxSum;
    }
};
