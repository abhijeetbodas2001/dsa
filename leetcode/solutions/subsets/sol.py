from typing import List, Set


class Solution:
    def _generate_subsets(
        self,
        nums: List[int],
        idx: int,
        curr_subset: Set[int],
        power_set: List[List[int]],
    ) -> None:
        if idx == len(nums):
            power_set.append(list(curr_subset))
            return

        curr_subset.add(nums[idx])
        self._generate_subsets(nums, idx + 1, curr_subset, power_set)

        curr_subset.remove(nums[idx])
        self._generate_subsets(nums, idx + 1, curr_subset, power_set)

    def subsets(self, nums: List[int]) -> List[List[int]]:
        # given elements in the array are unique
        assert sorted(set(nums)) == sorted(nums)

        curr_subset = set()
        power_set = []
        self._generate_subsets(nums, 0, curr_subset, power_set)

        return list(power_set)
