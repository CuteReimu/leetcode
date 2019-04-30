class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int arr[] = {a, b, c};
        sort(arr, arr+3);
        int x = arr[0], y = arr[1], z = arr[2];
        int ansa = 0;
        if (x < y - 1) ansa++;
        if (y < z - 1) ansa++;
        if (x == y - 2 || y == z - 2) ansa = 1;
        int ansb = z - x - 2;
        vector<int> vec;
        vec.push_back(ansa);
        vec.push_back(ansb);
        return vec;
    }
};
