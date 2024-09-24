#%%
from typing import List, Optional


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def _process_layer(self, layer: List[TreeNode], ans: List[List[int]]):
        if len(layer) == 0:
            return

        next_layer = []

        for node in layer:
            for child in [node.left, node.right]:
                if child is not None:
                    next_layer.append(child)

        self._process_layer(next_layer, ans)

        # append the answer after processing all child layers
        ans.append(list(x.val for x in layer))

    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        # without reversing the result
        if root is None:
            return []

        ans = []
        self._process_layer([root], ans)
        return ans

