# %%
from collections import deque
from typing import List, Set


class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        neighbors: List[Set[int]] = [set() for _ in range(n)]

        if n == 1:
            return [0]
        if n == 2:
            return [0, 1]

        for from_, to_ in edges:
            neighbors[from_].add(to_)
            neighbors[to_].add(from_)

        # start from ANY node
        start = 0
        # the farthest point found while doing this will be one
        # of the ends of the longest path in the graph
        stack = deque()
        stack.append(start)
        color = [0 for _ in range(n)]
        depth = [0 for _ in range(n)]
        diameter_end_1 = start
        while stack:
            node = stack.pop()
            color[node] = 1

            for neighbor in neighbors[node]:
                if color[neighbor] == 1:
                    continue

                # Assigning depth like this works because we are in
                # a tree, and there is only one path to reach a node.
                # In a graph, doing BFS gives the shortest path to each
                # node
                depth[neighbor] = depth[node] + 1
                stack.append(neighbor)

                if depth[neighbor] > depth[diameter_end_1]:
                    diameter_end_1 = neighbor

        # starting from one end of diameter, do DFS again to find other end
        stack = deque()
        stack.append(diameter_end_1)
        color = [0 for _ in range(n)]
        depth = [0 for _ in range(n)]
        diameter_end_2 = diameter_end_1

        # parent info will later be used to connect the diameter
        parent = [0 for _ in range(n)]
        parent[diameter_end_1] = -1
        while stack:
            node = stack.pop()
            color[node] = 1

            for neighbor in neighbors[node]:
                if color[neighbor] == 1:
                    continue

                depth[neighbor] = depth[node] + 1
                parent[neighbor] = node
                stack.append(neighbor)

                if depth[neighbor] > depth[diameter_end_2]:
                    diameter_end_2 = neighbor

        diameter = depth[diameter_end_2]
        dist_to_middle = [diameter // 2]
        if diameter % 2 == 1:
            dist_to_middle = [diameter // 2, diameter // 2 + 1]

        ans = []
        node = diameter_end_2
        dist = 0
        while node != diameter_end_1:
            node = parent[node]
            dist += 1
            if dist in dist_to_middle:
                ans.append(node)

        assert len(ans) <= 2
        return ans


assert Solution().findMinHeightTrees(
    8, [[0, 1], [1, 2], [2, 3], [0, 4], [4, 5], [4, 6], [6, 7]]
) == [0]

assert Solution().findMinHeightTrees(
    8, [[0, 1], [1, 2], [2, 3], [0, 4], [7, 5], [4, 6], [6, 7]]
) == [0, 4]

assert Solution().findMinHeightTrees(5, [[0, 1], [1, 2], [2, 3], [3, 4]]) == [2]

assert Solution().findMinHeightTrees(5, [[0, 1], [0, 2], [0, 3], [0, 4]]) == [0]

assert Solution().findMinHeightTrees(1, []) == [0]
assert Solution().findMinHeightTrees(2, [[0, 1]]) == [0, 1]
