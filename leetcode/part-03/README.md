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
