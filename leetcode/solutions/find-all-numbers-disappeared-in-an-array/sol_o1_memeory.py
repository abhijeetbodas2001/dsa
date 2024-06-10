# https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/


class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range(n):
            index_to_mark = abs(nums[i]) - 1
            nums[index_to_mark] = -1 * abs(nums[index_to_mark])

        missing_nums = []
        for i in range(n):
            if nums[i] > 0:
                missing_nums.append(i + 1)

        return missing_nums
