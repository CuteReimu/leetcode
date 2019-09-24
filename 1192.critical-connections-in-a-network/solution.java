class Solution {
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        dfn = new int[n + 1];
        low = new int[n + 1];
        for (int i = 0; i <= n; i++)
            cache.add(new ArrayList<>());
        for (List<Integer> t : connections) {
            cache.get(t.get(0)).add(t.get(1));
            cache.get(t.get(1)).add(t.get(0));
        }
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == 0) {
                tarjan(i, -1);
            }
        }
        return res;
    }

    private void tarjan(int x, int p) {
        dfn[x] = low[x] = ++num;
        for (int y : cache.get(x)) {
            if (dfn[y] == 0)
            {
                tarjan(y, x);
                low[x] = Math.min(low[y], low[x]);
                if (low[y] > dfn[x]) {
                    res.add(Arrays.asList(x, y));
                }
            } else if (y != p) {
                low[x] = Math.min(low[x], dfn[y]);
            }
        }
    }

    private List<List<Integer>> res = new ArrayList<>();
    private int[] dfn, low;
    private List<List<Integer>> cache = new ArrayList<>();
    private int num;
}
