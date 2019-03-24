class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (const int &i : A)
            sum += i;
        if (sum % 3 != 0) return false;
        sum /= 3;
        int tmp = 0;
        int i;
        for (i = 0; i < A.size(); i++) {
            tmp += A[i];
            if (tmp == sum)
                break;
        }
        i++;
        if (i >= A.size()) return false;
        tmp = 0;
        for (; i < A.size(); i++) {
            tmp += A[i];
            if (tmp == sum)
                break;
        }
        i++;
        if (i >= A.size()) return false;
        tmp = 0;
        for (; i < A.size(); i++) {
            tmp += A[i];
        }
        return tmp == sum;
    }
};
