class Solution {
    public int rob(int[] nums) {
        switch (nums.length) {
            case 0: return 0;
            case 1: return nums[0];
            case 2: return Math.max(nums[0], nums[1]);
            case 3: return Math.max(Math.max(nums[0], nums[1]), nums[2]);
            default: break;
        }
        int val;
        {
            int a1 = 0, a2 = 0, a3 = nums[0];
            for (int i = 1; i < nums.length - 1; i++) {
                int newA3 = Math.max(a1, a2) + nums[i];
                a1 = a2;
                a2 = a3;
                a3 = newA3;
            }
            val = Math.max(a2, a3);
        }
        {
            int a1 = 0, a2 = 0, a3 = nums[1];
            for (int i = 2; i < nums.length; i++) {
                int newA3 = Math.max(a1, a2) + nums[i];
                a1 = a2;
                a2 = a3;
                a3 = newA3;
            }
			val = Math.max(val, Math.max(a2, a3));
        }
        return val;
    }
}
