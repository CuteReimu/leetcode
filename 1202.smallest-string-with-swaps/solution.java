class Solution {
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        char[] result = s.toCharArray();
        int len = s.length();
        int[] parent = new int[len];
        int[] deep = new int[len];
        Map<Integer, List<Integer>> cache = new HashMap<>();
        for (int i = 0; i < len; i++) {
            parent[i] = i;
            deep[i] = 0;
        }
        for (List<Integer> pair : pairs) {
            int x = pair.get(0), y = pair.get(1);
            x = find(parent, x);
            y = find(parent, y);
            if (x == y) continue;
            if (deep[x] < deep[y])
                parent[x] = y;
            else {
                parent[y] = x;
                if (deep[x] == deep[y])
                    deep[x]++;
            }
        }

        for (int i = 0; i < len; i++) {
            int k = find(parent, i);
            List<Integer> l = cache.get(k);
            if (l == null) {
                l = new ArrayList<>();
                cache.put(k, l);
            }
            l.add(i);
        }

        for (List<Integer> l : cache.values())
        {
            char[] tmp = new char[l.size()];
            for (int j = 0; j < l.size(); j++)
                tmp[j] = s.charAt(l.get(j));
            Arrays.sort(tmp);
            for (int j = 0; j < l.size(); j++) {
                result[l.get(j)] = tmp[j];
            }
        }
        return new String(result);
    }

    private int find(int[] parent, int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]);
    }
}
