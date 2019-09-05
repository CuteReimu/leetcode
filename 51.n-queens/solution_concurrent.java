import java.util.concurrent.*;

class Solution extends RecursiveTask<List<List<String>>> {
    public Solution() {
    }

    public List<List<String>> solveNQueens(int n) {
        if (n == 1) return Collections.singletonList(Collections.singletonList("Q"));
        if (n <= 3) return Collections.emptyList();
        sum = new boolean[n * 2 - 1];
        diff = new boolean[n * 2 - 1];
        line = new boolean[n];
        list = new ArrayList<>();
        result = new ArrayList<>();
        this.n = n;
        return compute();
    }

    public Solution(Solution s) {
        n = s.n;
        list = new ArrayList<>(s.list);
        sum = Arrays.copyOf(s.sum, s.sum.length);
        diff = Arrays.copyOf(s.diff, s.diff.length);
        line = Arrays.copyOf(s.line, s.line.length);
        result = new ArrayList<>();
    }

    public Solution(int n) {
        sum = new boolean[n * 2 - 1];
        diff = new boolean[n * 2 - 1];
        line = new boolean[n];
        list = new ArrayList<>();
        result = new ArrayList<>();
        this.n = n;
    }

    @Override
    protected List<List<String>> compute() {
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
            return null;
        }
        List<ForkJoinTask<List<List<String>>>> tasks = new ArrayList<>();
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
            if (j <= 2)
                tasks.add(new Solution(this).fork());
            else
                compute();
            line[i] = false;
            sum[i + j] = false;
            diff[diffVal] = false;
        }
        list.remove(j);
        for (ForkJoinTask<List<List<String>>> task : tasks) {
            List<List<String>> val = task.join();
            if (val != null)
                result.addAll(val);
        }
        return result;
    }

    private transient List<List<String>> result;
    private int n;
    private List<Integer> list;
    private boolean[] sum;
    private boolean[] diff;
    private boolean[] line;
}
