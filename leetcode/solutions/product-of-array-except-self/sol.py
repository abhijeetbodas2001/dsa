from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        assert n > 1

        # ans hold suffix product
        ans = [nums[n-1] for _ in range(n)]
        for i in range(n-2, -1, -1):
            ans[i] = nums[i] * ans[i+1]

        # nums holds prefix product
        for i in range(1, n):
            nums[i] = nums[i] * nums[i-1]

        # now modify ans in place to store the actual answers
        ans[0] = ans[1]
        for i in range(1, n-1):
            ans[i] = nums[i-1] * ans[i+1]
        ans[n-1] = nums[n-2]

        return ans
