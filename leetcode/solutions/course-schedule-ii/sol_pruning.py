# %%
from collections import deque
from typing import List, Set, Tuple


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        n = numCourses
        preqs = [set() for _ in range(n)]
        parents = [set() for _ in range(n)]
        for after, before in prerequisites:
            preqs[after].add(before)
            parents[before].add(after)

        q = deque()
        for node in range(n):
            if len(preqs[node]) == 0:
                q.append(node)

        ans = []
        while q:
            # process one layer at a time
            layer = []
            for _ in range(len(q)):
                node = q.popleft()
                assert len(preqs[node]) == 0
                layer.append(node)

                for parent in parents[node]:
                    preqs[parent].remove(node)
                    if len(preqs[parent]) == 0:
                        q.append(parent)

            ans.extend(layer)

        if len(ans) != n:
            # this means that cycle was detected (since not all
            # nodes were pushed to q)
            return []

        return ans


assert Solution().findOrder(
    8, [[2, 1], [7, 3], [7, 5], [1, 0], [3, 2], [4, 6], [3, 4], [5, 4]]
) == [0, 6, 1, 4, 2, 5, 3, 7]

assert Solution().findOrder(3, [[1, 2], [0, 1], [1, 0]]) == []

assert Solution().findOrder(6, [[1, 0], [2, 1], [4, 3], [3, 2], [2, 4], [4, 5]]) == []
