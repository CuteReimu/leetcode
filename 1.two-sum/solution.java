class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> cache = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++)
            cache.put(nums[i], i);
        for (int i = 0; i < nums.length; i++)
        {
            int a = target - nums[i];
            if (cache.containsKey(a))
            {
                int[] result = {i, cache.get(a)};
                if (result[0] != result[1])
                    return result;
            }
        }
        int[] result = {};
        return result;
    }
}
