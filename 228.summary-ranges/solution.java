class Solution {
    public List<String> summaryRanges(int[] nums) {
        if (nums.length == 0) return Collections.emptyList();
        int last = nums[0];
        int from = nums[0];
        List<String> result = new ArrayList<>();
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == last + 1) {
                last = nums[i];
                continue;
            }
            if (last == from) {
                result.add(Integer.toString(last));
            } else {
                result.add(from + "->" + last);
            }
            from = last = nums[i];
        }
        if (last == from) {
            result.add(Integer.toString(last));
        } else {
            result.add(from + "->" + last);
        }
        return result;
    }
}
