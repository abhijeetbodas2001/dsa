# https://leetcode.com/problems/move-zeroes/


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        first_zero = 0
        for i in range(len(nums)):
            if nums[first_zero] != 0:
                first_zero = first_zero + 1
                continue

            if nums[i] != 0:
                nums[first_zero]= nums[i]
                first_zero = first_zero + 1
                nums[i] = 0
