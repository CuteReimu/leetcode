class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> cache = new HashMap<>();
        for (int i = 0; i < nums.length; i++)
        {
            Integer j = cache.putIfAbsent(nums[i], i);
            if (j != null && nums[i] * 2 == target)
                return new int[]{i, j};
        }
        Arrays.sort(nums);
        int i = 0;
        int j = nums.length - 1;
        for (; i < j;)
        {
            int s = nums[i] + nums[j];
            if (s == target)
                return new int[]{cache.get(nums[i]), cache.get(nums[j])};
            if (s > target)
                j--;
            else
                i++;
        }
        return null;
    }
}
