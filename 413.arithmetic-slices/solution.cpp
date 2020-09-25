class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int i = 0, j = 2;
        int dist = A[1] - A[0];
        vector<int> v;
        while (j < A.size()) {
            if (A[j] - A[j - 1] != dist)
            {
                v.push_back(j - i);
                dist = A[j] - A[j - 1];
                i = j - 1;
            }
            j++;
        }
        v.push_back(j - i);
        int sum = 0;
        for (int len : v) {
            sum += (len - 2) * (len - 1) / 2;
        }
        return sum;
    }
};
