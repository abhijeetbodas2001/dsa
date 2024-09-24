#%%
from typing import List


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        """
        NOTE: XORing will not work, because even though only a single number
        is repeated, it can be repeated multiple times.
        [3, 3, 3, 3, 3] is a valid input

        Solution: Floyd's algorithm: https://www.youtube.com/watch?v=wjYnzkAhcNk
        """

        slow, fast = 0, 0 # hold array indices

        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if fast == slow:
                break

        slow2 = 0
        while slow != slow2:
            slow = nums[slow]
            slow2 = nums[slow2]

        return slow2

Solution().findDuplicate([1,1,1,2])

