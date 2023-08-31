## Contents

This part contains problems on these topics:
- BFS
- DFS
- Graph


## Algorithms

- [In-order iterative DFS](/vanilla-algorithms/iterative_in-order_dfs.cpp)
- [Breadth first search](/vanilla-algorithms/bfs.cpp)

## Notes

- For BST, the best solution one can get is usually `O(h)` time (not `O(N)`),
so try to get to that. In-order traversals are great for BST's.

- For tracking max, min values, use pointers/pass-by-reference in recursive functions.
No need to block the return value for this.

- Path-dependent problems are difficult to solve iteratively. You need to attach some data for
the path on each node in the stack, which can blow up the space complexity. Best to do recursively.
Example:
    - Path sums
    - Finding cycles in directed graphs (need to search in recursion stack)

- If it is difficult to backtrack using recursion, it may be usefult to save the parents of each
node in a map/vector and then go from the leaf to the root. See "minimum height trees" longest path
solution for an example


## Problems

|Serial number|Difficulty|Problem|Solution(s)|
|-|-|-|-|
|01|Easy|[Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree)|
|02|Easy|[Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree)|
|03|Easy|[Same Tree](https://leetcode.com/problems/same-tree)|
|04|Easy|[Path Sum](https://leetcode.com/problems/path-sum)|
|05|Easy|[Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree)|
|06|Easy|[Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree)|
|07|Easy|[Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees)|
|08|Easy|[Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree)|
|09|Easy|[Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree)|
|10|Easy|[Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths)|
|11|Medium|[Target Sum](https://leetcode.com/problems/target-sum)|
|12|Medium|[Clone Graph](https://leetcode.com/problems/clone-graph)|
|13|Medium|[Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow)|
|14|Medium|[Number of Islands](https://leetcode.com/problems/number-of-islands)|
|15|Medium|[Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree)|
|16|Medium|[Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph)|
|17|Medium|[Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst)|
|18|Medium|[Course Schedule](https://leetcode.com/problems/course-schedule)|
|19|Medium|[Course Schedule II](https://leetcode.com/problems/course-schedule-ii)|
|20|Medium|[Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees)|
|21|Medium|[Sequence Reconstruction](https://leetcode.com/problems/sequence-reconstruction)|
|22|Medium|[Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii)|
|23|Medium|[Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal)|
|24|Medium|[Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal)|
|25|Medium|[Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node)|
|26|Medium|[Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii)|
|27|Medium|[Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view)|
|28|Medium|[All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree)|
|29|Medium|[Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree)|
|30|Medium|[Path Sum II](https://leetcode.com/problems/path-sum-ii)|
|31|Medium|[Path Sum III](https://leetcode.com/problems/path-sum-iii)|
|32|Medium|[Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree)|
|33|Medium|[Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree)|
|34|Medium|[Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree)|
|35|Medium|[Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal)|
|36|Medium|[Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree)|
|37|Hard|[Alien Dictionary](https://leetcode.com/problems/alien-dictionary)|
|38|Hard|[Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum)|
|39|Hard|[Word Search II](https://leetcode.com/problems/word-search-ii)|
|40|Hard|[Sort Items by Groups Respecting Dependencies](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies)|
