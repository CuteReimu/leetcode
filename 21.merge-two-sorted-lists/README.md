https://leetcode.cn/problems/merge-two-sorted-lists

这道题的Erlang解法其实是违背了“拼接给定的两个链表的所有节点”的要求的。不过，对于一个函数式编程语言，本身就无法修改已有变量的值，也就无从谈“拼接”了。所以，[这里给出的Erlang解法](solution.erl)纯粹就是排序重组。
