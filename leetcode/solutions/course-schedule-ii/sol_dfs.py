from collections import deque
from typing import List, Set, Tuple


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # children of a course are courses which can be taken immediately after it
        children: List[Set[int]]= [set() for _ in range(numCourses)]
        for after, before in prerequisites:
            children[before].add(after)

        # 0 -> white -> not processed
        # 1 -> grey -> processing / in current path
        # 2 -> black -> completed processing
        # see comments in solution of course schedule I for explanation of coloring logic
        color: List[int] = [0 for _ in range(numCourses)]

        toposort_all = []
        for start in range(numCourses):
            if color[start] == 2:
                continue

            assert color[start] != 1

            toposort_component = []
            stack = deque()
            stack.append(start)

            while stack:
                # peek only, do not pop just yet
                node = stack[len(stack)-1]

                if color[node] == 2:
                    # this node got processed via some other path
                    stack.pop()
                    continue

                if color[node] == 1:
                    # all children have been processed, mark this as completed
                    color[node] = 2
                    toposort_component.append(node)
                    stack.pop()
                    continue

                color[node] = 1
                for child in children[node]:
                    if color[child] == 1:
                        # cycle detected
                        return []

                    stack.append(child)

            toposort_all.extend(toposort_component)

        return list(reversed(toposort_all))
