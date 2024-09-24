from typing import List, Optional
from collections import deque

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        q = deque()
        q.append(root)
        ans = []

        while q:
            ans.append(list(x.val for x in q))

            for _ in range(len(q)):
                node = q.popleft()
                if node.left is not None:
                    q.append(node.left)

                if node.right is not None:
                    q.append(node.right)

        return ans

