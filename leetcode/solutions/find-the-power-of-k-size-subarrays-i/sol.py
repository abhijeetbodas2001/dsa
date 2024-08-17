from typing import List


class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        assert k <= n
        if k == 1:
            return nums

        first_sub_array_is_sorted = True
        for i in range(1, k):
            if nums[i - 1] >= nums[i]:
                first_sub_array_is_sorted = False

        ans = [nums[k - 1]]
        right = k - 1
        left = 0
        if not first_sub_array_is_sorted or not (nums[right] - (k-1) == nums[right - k + 1]):
            ans[0] = -1

        if not first_sub_array_is_sorted:
            left = k-1
            while left>=0 and nums[left] <= nums[left+1]:
                left-=1


        for i in range(k, n):
            right = i
            if nums[right] <= nums[right - 1]:
                left = right

            if (right - left + 1 >= k) and (nums[right] - (k-1) == nums[right - k + 1]):
                ans.append(nums[right])
            else:
                ans.append(-1)

        return ans
