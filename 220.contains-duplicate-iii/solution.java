class Solution {
	public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
		if (t < 0) return false;
		TreeSet<Integer> set = new TreeSet<>();
		for (int i = 0; i < nums.length; i++) {
			if (i > k) set.remove(nums[i - k - 1]);
			long a = (long) nums[i] - t;
			long b = (long) nums[i] + t;
			if (!set.subSet(a >= Integer.MIN_VALUE ? (int) a : Integer.MIN_VALUE, true, b <= Integer.MAX_VALUE ? (int) b : Integer.MAX_VALUE, true).isEmpty())
				return true;
			set.add(nums[i]);
		}
		return false;
	}
}
