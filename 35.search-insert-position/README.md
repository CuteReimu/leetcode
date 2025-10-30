https://leetcode.cn/problems/search-insert-position

由于Erlang的列表没法二分查找，如果自行复制一份数组，复制的过程的时间复杂度已经是O(N)了，没有意义，因此就直接遍历了。
