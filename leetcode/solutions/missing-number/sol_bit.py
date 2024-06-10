# https://leetcode.com/problems/missing-number/


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        xor_value = len(nums)
        for i in range(len(nums)):
            xor_value = xor_value ^ nums[i] ^ i

        return xor_value
