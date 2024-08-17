# https://leetcode.com/problems/single-number/


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # Identity: x ^ x = 1 for all integer x
        ans = 0
        for n in nums:
            ans = ans ^ n

        return ans
