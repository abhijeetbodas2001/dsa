from collections import defaultdict, deque
from typing import Deque, Dict, List, Optional, Set


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    """
    Converts to graph, and start from target as new root
    Can also do by keeping track of parent: https://www.youtube.com/watch?v=i9ORlEy6EsI
    """
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        if root is None:
            return []

        # construct graph from binary tree
        q: Deque[TreeNode] = deque()  # this queue will contain TreeNodes
        q.append(root)

        # because it is given that all values are unique, we can use set of
        # ints
        neighbors: Dict[int, Set[int]] = defaultdict(set)
        while q:
            node = q.pop()

            for child in [node.left, node.right]:
                if child is None:
                    continue

                neighbors[child.val].add(node.val)
                neighbors[node.val].add(child.val)
                q.append(child)

        # use bfs to find nodes at depth k from target
        q: Deque[int] = deque()
        q.append(target.val)  # here, q will contain the vals of the nodes
        visited: Set[int] = set()
        level = 0

        while q:
            if level == k:
                return list(q)
            level += 1
            for _ in range(len(q)):
                node = q.popleft()

                for child in neighbors[node]:
                    if child in visited:
                        continue

                    q.append(child)

                visited.add(node)

        return []
