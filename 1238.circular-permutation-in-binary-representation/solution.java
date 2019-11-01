class Solution {
    public List<Integer> circularPermutation(int n, int start) {
        List<Integer> list = new ArrayList<>();
        list.add(0);
        int total = 1;
        for (int i = 0; i < n; i++) {
            int len = list.size();
            for (int j = 0; j < len; j++)
                list.add(total + list.get(len - 1 - j));
            total <<= 1;
        }
        int index;
        for (index = 0; list.get(index) != start; index++);
        List<Integer> list2 = new ArrayList<>();
        int len = list.size();
        for (int i = 0; i < len; i++) {
            list2.add(list.get((index + i) % len));
        }
        return list2;
    }
}
