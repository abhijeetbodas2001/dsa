from typing import List, Set
from collections import Counter


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        counts = Counter(nums)
        power_set = [[]]

        for num, count in counts.items():
            subset_with_num = []

            # "subset" contains "y" number of "num"s, where
            # y is in [0, count]
            subset = list(power_set)  # y = 0
            for _ in range(count):
                subset = [curr + [num] for curr in subset]
                subset_with_num.extend(subset)

            power_set.extend(subset_with_num)

        return power_set
