#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int>::iterator itr = hashMap.find(target - nums[i]);
            if (itr != hashMap.end())
            {
                result.push_back(i);
                result.push_back(itr->second);
                return result;
            } else
            {
                hashMap[nums[i]] = i;
            }
        }
        return result;
    }
};
