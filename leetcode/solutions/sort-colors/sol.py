from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        n = len(nums)
        # 3 pointers
        curr = 0  # current position
        left = 0  # the first index pointing to a non-zero value
        right = (
            n - 1
        )  # the first index poiniting to a non-two value, from the right end of the array

        for curr in range(left, n):
            while left < n and nums[left] == 0:
                left += 1
            while right > 0 and nums[right] == 2:
                right -= 1

            if nums[curr] == 1:
                continue

            if curr > right or curr < left:
                # these are in their corrct place
                assert nums[curr] in [0, 2]
                continue

            for _ in range(2):
                # Do this two times, because we can swap a 2 for a 0, or swap a
                # 0 for a 2
                if nums[curr] == 0:
                    nums[curr], nums[left] = nums[left], nums[curr]

                if nums[curr] == 2:
                    nums[curr], nums[right] = nums[right], nums[curr]


x = [0, 1, 0, 2]
Solution().sortColors(x)
print(x)

x = [2, 1, 0, 2]
Solution().sortColors(x)
print(x)

x = [2, 1, 0, 0]
Solution().sortColors(x)
print(x)

x = [2, 0, 2, 1, 1, 0]
Solution().sortColors(x)
print(x)

x = [2]
Solution().sortColors(x)
print(x)

x = [0]
Solution().sortColors(x)
print(x)

x = [1, 2, 0]
Solution().sortColors(x)
print(x)
