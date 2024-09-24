# %%
from typing import List


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        """
        Store information about what is repeated by modifying
        input array.
        """
        # [4,3,2,7,8,2,3,1]
        # [8+3,8+8+2,8+8+1,8+6,7,1,8+2,8+0]

        for idx in range(len(nums)):
            # now, all nums lie in [0, len(nums)-1]
            nums[idx] -= 1

        for idx, num in enumerate(nums):
            # If a number is repeated many times, this can
            # get very large.
            # There is actually no need to increment again, if
            # it has already been incremented earlier (add an if
            # check)
            nums[num % len(nums)] += len(nums)

        ans = []
        for idx, num in enumerate(nums):
            if num // len(nums) == 2:
                ans.append(idx + 1)

        return ans


Solution().findDuplicates([2, 2])
Solution().findDuplicates([1, 2])
Solution().findDuplicates([4, 3, 2, 7, 8, 2, 3, 1])

# %%

x = [1, 2]
for i in x:
    i -= 1

# x does not change!
x
