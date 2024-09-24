from typing import List, Set


class Solution:
    def _generate_permutations(self) -> None:
        if not self.available:
            # Append a copy, because self.curr_permututation is going to
            # modified later on
            self.all_permutations.append(list(self.curr_permututation))
            return

        # Converting this to list will make a copy, will take time
        # proportional to size of "available"
        # Also, list append and pop can be slow
        for num in list(self.available):
            self.available.remove(num)
            self.curr_permututation.append(num)

            self._generate_permutations()

            self.curr_permututation.pop()
            self.available.add(num)

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.available = set(nums)
        self.all_permutations = []
        self.curr_permututation = []

        self._generate_permutations()

        return self.all_permutations


assert Solution().permute([]) == [[]], Solution().permute([])
assert Solution().permute([1]) == [[1]], Solution().permute([1])
assert Solution().permute([1,2]) == [[1, 2], [2, 1]], Solution().permute([1,2])

