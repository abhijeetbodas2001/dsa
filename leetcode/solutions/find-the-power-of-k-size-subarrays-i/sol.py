from typing import List


class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        assert k <= n

        if k == 1:
            return nums

        ans = [nums[k - 1]]

        # current element being processed
        right = k - 1
        # from left to right (both inclusive), elements are consqeutive and sorted
        left = k-1

        for i in range(k-1, 0, -1):
            if nums[i - 1] != nums[i] - 1:
                break

            left = i-1

        if left != 0:
            ans[0] = -1

        for i in range(k, n):
            right = i
            if nums[right] != nums[right - 1]+1:
                left = right
                ans.append(-1)
                continue

            if left <= right - (k-1):
                ans.append(nums[right])
            else:
                ans.append(-1)

        return ans
