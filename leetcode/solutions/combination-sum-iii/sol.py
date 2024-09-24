from typing import List


class Solution:
    def _genereate_combinations(
        self,
        k: int,
        nums: List[int],
        target: int,
        curr_comb: List[int],
        all_combs: List[List[int]],
        start_idx: int,
        curr_sum: int,
    ) -> None:
        if curr_sum > target:
            return

        if curr_sum == target:
            if not len(curr_comb) == k:
                return

            all_combs.append(curr_comb.copy())

        for idx in range(start_idx, len(nums)):
            num = nums[idx]
            curr_comb.append(num)
            self._genereate_combinations(
                k, nums, target, curr_comb, all_combs, idx + 1, curr_sum + num
            )
            curr_comb.pop()

    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        nums = list(range(1, 10))
        curr_comb = []
        all_combs = []

        self._genereate_combinations(k, nums, n, curr_comb, all_combs, 0, 0)
        return all_combs


print(f"{Solution().combinationSum3(3,7)=}")
print(f"{Solution().combinationSum3(3,9)=}")
