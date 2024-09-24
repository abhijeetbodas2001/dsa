from collections import deque
from itertools import count
from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        q = deque()
        q.append(root)
        ans = []

        for level in count(0):
            # assumption: things have been pushed to the q
            # in the correct order only
            ans.append(list(node.val for node in q))

            # why always reverse? take example on paper and see
            level_nodes = reversed(list(q))
            q = deque()

            # instead of doing reversed and then resetting the q,
            # can also just do q.popleft() every time

            for node in level_nodes:
                children = [node.left, node.right]
                if level % 2 == 0:
                    children = reversed(children)

                for child in children:
                    if child is None:
                        continue

                    q.append(child)

            if not q:
                break

        return ans
