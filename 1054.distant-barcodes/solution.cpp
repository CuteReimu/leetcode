class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        sort(barcodes.begin(), barcodes.end());
        vector<pair<int, int>> vec;
        int last = 0;
        int count = 0;
        for (int i : barcodes) {
            if (last != 0 && last != i)
            {
                vec.push_back(make_pair(count, last));
                count = 0;
            }
            last = i;
            count++;
        }
        vec.push_back(make_pair(count, last));
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        int index = 0;
        for (pair<int, int> &p : vec) {
            count = 0;
            while (count++ < p.first) {
                barcodes[index++] = p.second;
            }
        }
        vector<int> result(barcodes.size(), 0);
        index = -2;
        last = 0;
        for (int i : barcodes) {
            if (last != 0 && last != i) index++;
            else index += 2;
            if (index >= barcodes.size()) index = 0;
            while (result[index] != 0) index++;
            result[index] = i;
            last = i;
        }
        return result;
    }
};
