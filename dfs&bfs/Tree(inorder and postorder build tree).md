# [Tree(由中序和后序序列建树)](https://vjudge.net/contest/241548#problem/J)

1. 题目大意：根据中序和后序序列建树

2. 解题思路：后序序列的最右一个数字是根节点的值，在中序序列中找到根则此时根的左边即为左子树的所有元素，右边即为右子树的所有元素

3. 学到的东西

   * 二叉树的存法，用两个数组lt[]和rt[]来存，其中lt[root]表示的是以root为根的左子结点，rt[root]表示的是以root为根的右子结点，这道题可以这样存是因为二叉树的结点的值是唯一的且均在1~10000之间

   * 一行一行读入数据

```c++
	string line;
    getline(cin,line);
    stringstream ss(line);
    n = 0;
    int x;
    while(ss >> x)
        a[n++] = x;
```

