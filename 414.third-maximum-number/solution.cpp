class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> cache;
        for (int i : nums)
        {
            cache.insert(i);
            if (cache.size() > 3)
                cache.erase(cache.begin());
        }
        if (cache.size() < 3) return *cache.rbegin();
        auto it = cache.rbegin();
        it++;
        it++;
        return *it;
    }
};
