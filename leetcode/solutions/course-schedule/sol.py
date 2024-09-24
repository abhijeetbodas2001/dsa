# REVISIT
from collections import deque
from typing import List, Set


class Solution:
    """
    Finding cycle in DIRECTED graph -> BFS cannot be used, must use
    DFS: https://stackoverflow.com/a/2869661

    Iterative DFS for cycle detection (coloring): https://stackoverflow.com/a/62971341
    """

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # convert edges to adjacency list
        children: List[Set[int]] = [set() for _ in range(numCourses)]

        for before, after in prerequisites:
            children[after].add(before)

        # 0 for white (unprocessed)
        # 1 for grey (in path, processing)
        # 2 for black (done processing)
        color = [0 for _ in range(numCourses)]

        for start in range(numCourses):
            if color[start] == 2:
                # has been processed before
                continue

            assert color[start] != 1

            stack = deque()
            stack.append(start)
            while stack:
                # only peek, do not pop
                node = stack[len(stack) - 1]

                if color[node] == 2:
                    # this can happen if there are multiple paths to reach parent
                    # NOTE: having this check only at the time of appending children
                    # below is not sufficient
                    # Example:
                    # 0 -> 2 -> 1
                    # 0 ------> 1
                    # this will give the stack: 0 1 2 1
                    # both ones were appended to the stack when they were WHITE
                    # but the 2nd one will mark both ones as BLACK when it is processed
                    # when the 1st one is popped, it will also be black
                    stack.pop()
                    continue

                if color[node] == 1:
                    # parent is at top of stack, after all its children have
                    # been processed and popped
                    # mark it as processed, and remove from stack
                    color[node] = 2
                    stack.pop()
                    continue

                # set parent as processing
                color[node] = 1
                for child in children[node]:
                    if color[child] == 1:
                        # child is present in the current path
                        # cycle detected
                        return False

                    if color[child] == 2:
                        # given that we anyways need this check above,
                        # the check here can be safely removed
                        continue

                    stack.append(child)

        return True
