# https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/


class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        num_set = set(nums)
        all_set = set(range(1, len(nums) + 1))
        return list(all_set - num_set)
