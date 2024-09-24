from typing import List, Set
from collections import deque


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        perms = [[]]  # holds all permutations

        for num in nums:
            # holds permutations which were built on top of perms,
            # but this time also including "num"
            perms_containing_num = []

            for p in perms:
                # insert "num" in each possible position of p
                # it can be inserted in len(p)+1 places
                for idx in range(len(p) + 1):
                    # Slicing and joining are expensive!
                    # takes O(n) time
                    perms_containing_num.append(p[:idx] + [num] + p[idx:])
                    # Or, create a copy and use list.insert

            perms = perms_containing_num

        return perms


assert Solution().permute([]) == [[]], Solution().permute([])
assert Solution().permute([1]) == [[1]], Solution().permute([1])
assert Solution().permute([1, 2]) == [[2, 1], [1, 2]]
