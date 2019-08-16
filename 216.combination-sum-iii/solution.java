class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        return combinationSum3(k, 1, n);
    }
    
    private List<List<Integer>> combinationSum3(int k, int start, int n) {
        if (n == 0 && k == 0) {
            return Arrays.asList((List) new ArrayList<Integer>());
        }
        if (start > 9 || k <= 0) return new ArrayList<List<Integer>>();
        if (k == 1) {
            if (n >= start && n <= 9) return Arrays.asList(Arrays.asList(n));
            return new ArrayList<List<Integer>>();
        }
        List<List<Integer>> ret = new ArrayList<>();
        for (int i = start; i <= 9; i++) {
            List<List<Integer>> result = combinationSum3(k - 1, i + 1, n - i);
            for (List<Integer> list : result) {
                List<Integer> list2 = new ArrayList<>();
                list2.add(i);
                list2.addAll(list);
                ret.add(list2);
            }
        }
        return ret;
    }
}
