from typing import List


class Solution:
    def _generate_combinations(
        self,
        k: int,
        n: int,
        curr_comb: List[int],
        all_combs: List[List[int]],
        start_num: int,  # avoid duplicate combinations
    ) -> None:
        if len(curr_comb) == k:
            all_combs.append(curr_comb.copy())
            return

        if start_num > n:
            return

        for num in range(start_num, n + 1):
            # if we start from 0 again here, that will give duplicate
            # combinations. Hence, only look at those numbers which have
            # not been already considered (ie, those from start_num)
            curr_comb.append(num)
            self._generate_combinations(k, n, curr_comb, all_combs, num + 1)
            curr_comb.pop()

    def combine(self, n: int, k: int) -> List[List[int]]:
        all_combs = []
        curr_comb = []

        self._generate_combinations(k, n, curr_comb, all_combs, 1)
        return all_combs


print(f"{Solution().combine(3,1)=}")
print(f"{Solution().combine(3,2)=}")
print(f"{Solution().combine(3,3)=}")

print(f"{Solution().combine(1,3)=}")
print(f"{Solution().combine(1,1)=}")

print(f"{Solution().combine(0,1)=}")

print(f"{len(Solution().combine(10,3))=}")
