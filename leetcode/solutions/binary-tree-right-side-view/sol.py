from collections import deque
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        q = deque()
        q.append(root)

        ans = []
        while q:
            # for each level, just look at the right most
            # node
            ans.append(q[len(q)-1].val)

            for _ in range(len(q)):
                # be careful about which pop to use!i
                node = q.popleft()

                for child in [node.left, node.right]:
                    if child is None:
                        continue

                    q.append(child)


        return ans
