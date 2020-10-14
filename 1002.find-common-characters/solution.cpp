class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        string &s = A.front();
        int arr[26] = {0};
        for (char c : s) {
            arr[c - 'a']++;
        }
        for (int i = 1; i < A.size(); i++) {
            int arr0[26] = {0};
            for (char c : A[i]) {
                arr0[c - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                arr[j] = min(arr[j], arr0[j]);
            }
        }
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < arr[i]; j++) {
                result.emplace_back(1, 'a' + i);
            }
        }
        return result;
    }

private:
    void toArr(const string &s, int (&arr)[26]) {
        for (char c : s) {
            arr[c - 'a']++;
        }
    }
};
