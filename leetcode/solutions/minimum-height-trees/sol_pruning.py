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

        q = deque()
        for node in range(n):
            if len(neighbors[node]) == 1:
                q.append(node)

        level_width = len(q)
        while True:
            node = q.popleft()
            assert len(neighbors[node]) == 1

            neighbor = neighbors[node].pop()
            neighbors[neighbor].remove(node)

            if len(neighbors[neighbor]) == 1:
                q.append(neighbor)

            # this must be after neighbors processing is done
            level_width -= 1
            if level_width == 0:
                level_width = len(q)

                if level_width == 1:
                    break
                if level_width == 2 and q[0] in neighbors[q[len(q) - 1]]:
                    break

        return list(q)


assert Solution().findMinHeightTrees(6, [[0, 1], [0, 2], [0, 3], [0, 4], [0, 5]]) == [0]
assert Solution().findMinHeightTrees(6, [[0, 1], [0, 2], [0, 3], [0, 4], [4, 5]]) == [
    0,
    4,
]
assert Solution().findMinHeightTrees(
    9, [[0, 1], [1, 2], [2, 3], [3, 4], [4, 5], [3, 6], [6, 7], [7, 8]]
) == [3]
