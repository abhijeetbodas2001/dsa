# %%
from typing import List


class Solution:
    def _calculate_depth(self, head, depth_memo):
        """
        Depth is defined as the length of the sequence of numbers
        present in nums, starting from x, and decreasing
        """
        if depth_memo[head] != -1:
            # This has been calculated before
            return depth_memo[head]

        if head - 1 not in depth_memo.keys():
            depth = 1
        else:
            depth = 1 + self._calculate_depth(head - 1, depth_memo)

        depth_memo[head] = depth
        return depth

    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        depth = dict(zip(nums, [-1] * len(nums)))

        for n in depth.keys():
            # We do not actually need to calculate depth for
            # every element in the array
            # Doing so only for the largest element of the sequence
            # (n for which n+1 not in nums) should suffice
            # Then, keep a running max of the depth, to altogether
            # ditch the depth dict (will still need a hashset for "in"
            # check)
            self._calculate_depth(n, depth)

        return max(depth.values())


Solution().longestConsecutive([1, 2])
