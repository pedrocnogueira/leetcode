# 222. Count Complete Tree Nodes

Given the `root` of a **complete** binary tree, return the number of nodes in the tree.

According to *Wikipedia*,
in a complete binary tree every level, except possibly the last, is completely filled,
and all nodes on the last level are as far left as possible.  
The last level `h` can contain between `1` and `2^h` nodes (inclusive).

Design an algorithm that runs in less than `O(n)` time complexity.

---

### Example 1:

          1
        /   \
       2     3
      / \   /
     4  5  6


**Input:** `root = [1,2,3,4,5,6]`  
**Output:** `6`

---

### Example 2:

**Input:** `root = []`  
**Output:** `0`

---

### Example 3:

**Input:** `root = [1]`  
**Output:** `1`

---

### Constraints:

- The number of nodes in the tree is in the range <code>[0, 5·10<sup>4</sup>]</code>.  
- <code>0 &lt;= Node.val &lt;= 5·10<sup>4</sup></code>.  
- The tree is guaranteed to be **complete**.

# My solution

The key observation is that the tree is **complete**. 
This means every level except possibly the last one is completely filled, 
and the only thing that can vary is how many nodes exist on the last level.

The first step is to compute the height `h` of the tree. 
Because the tree is complete, the height is just the length of the path from the root 
down the leftmost branch. We can walk down `root -> left -> left -> ...`, 
counting how many levels we visit.

Now for the tricky part of the problem, how can we figure out the amount of nodes in the last level?

The statement also tells us that all nodes on the last level are as far left as possible. 
In other words, the existing nodes on the last level form a contiguous block from left to right, 
with no gaps. That means if we can find the position of the last existing node 
(equivalently, the first `NULL` position after it), we immediately know 
how many nodes there are on that level.

Since the last level is filled from left to right with no gaps, 
the nodes on that level behave like a sorted array of positions: 
first some existing nodes, then only missing nodes. 

We can index the possible positions on the last level from `1` to `2^(h-1)` 
and ask a yes/no question for each index: “does the node at this position exist?”. 
Because the answer sequence looks like `true, true, ..., true, false, false, ..., false`, 
we can use binary search over these indices to find the last position that still returns `true`. 

This lets us determine the exact number of nodes on the last level in `O(log n)` calls to this 
existence check, instead of scanning all positions one by one.
