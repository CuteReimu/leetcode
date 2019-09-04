class Solution {
    public List<List<String>> solveNQueens(int n) {
        sum = new boolean[n * 2 - 1];
        diff = new boolean[n * 2 - 1];
        line = new boolean[n];
        List<List<String>> result = new ArrayList<>();
        solveNQueens(result, n, new ArrayList<>());
        return result;
    }

    private void solveNQueens(List<List<String>> result, int n, List<Integer> list) {
        int j = list.size();
        if (j == n) {
            List<String> strings = new ArrayList<>();
            for (int i : list) {
                char[] ch = new char[n];
                for (int x = 0; x < n; x++)
                    ch[x] = x == i ? 'Q' : '.';
                strings.add(new String(ch));
            }
            result.add(strings);
            return;
        }
        list.add(0);
        for (int i = 0; i < n; i++) {
            if (line[i]) continue;
            if (sum[i + j]) continue;
            int diffVal = i - j + n - 1;
            if (diff[diffVal]) continue;
            line[i] = true;
            sum[i + j] = true;
            diff[diffVal] = true;
            list.set(j, i);
            solveNQueens(result, n, list);
            line[i] = false;
            sum[i + j] = false;
            diff[diffVal] = false;
        }
        list.remove(j);
    }

    private boolean[] sum;
    private boolean[] diff;
    private boolean[] line;
}
