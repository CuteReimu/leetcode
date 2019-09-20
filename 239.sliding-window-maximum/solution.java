class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0 && k == 0) return new int[0];
        LinkedList<Integer> cache = new LinkedList<>();
        for (int i = 0; i < k - 1; i++) {
            while (!cache.isEmpty() && cache.peekLast() < nums[i]) cache.pollLast();
            cache.addLast(nums[i]);
        }
        int[] result = new int[nums.length - k + 1];
        for (int i = k - 1; i < nums.length; i++) {
            while (!cache.isEmpty() && cache.peekLast() < nums[i]) cache.pollLast();
            cache.addLast(nums[i]);
            result[i - k + 1] = cache.peekFirst();
            if (cache.peekFirst() == nums[i - k + 1]) cache.pollFirst();
        }
        return result;
    }

}
