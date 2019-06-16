class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
		vector<int> arr2(arr.size(), 0);
        int j = 0;
        for (int i = 0; j < arr.size(); i++, j++) {
            arr2[j] = arr[i];
            if (arr[i] == 0 && j + 1 < arr.size()) {
                arr2[++j] = 0;
            }
        }
		arr = arr2;
    }
};
