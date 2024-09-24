from typing import List


class Solution:
    def _generate_combinations(
        self,
        candidates: List[int],
        start_idx: int,
        target: int,
        all_combs: List[List[int]],
        curr_comb: List[int],
        curr_sum: int,
    ) -> None:
        if curr_sum > target:
            return

        if curr_sum == target:
            all_combs.append(curr_comb.copy())
            return

        for idx in range(start_idx, len(candidates)):
            if idx > start_idx and candidates[idx] == candidates[idx - 1]:
                # It is NOT OK if we are using the same number again, in the same
                # recursive call
                # example: [1,1,1]: if start_idx=1, then selecting at idx=1 is OK,
                # because curr_comb will become [1,1]
                # selecting at idx=2 is NOT OK, because this will lead to curr_comb=[1,1]
                # again, which is a duplicate
                continue

            num = candidates[idx]

            curr_comb.append(num)
            self._generate_combinations(
                candidates,
                idx + 1,  # NOTE: idx+1 here
                target,
                all_combs,
                curr_comb,
                curr_sum + num,
            )
            curr_comb.pop()

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        # The optimization here is that instead of a counter dict, check
        # that adjacent elements are not chosen, to avoid duplicates
        # This does not give any significant speedup
        candidates = sorted(candidates)

        all_combs = []
        curr_comb = []

        self._generate_combinations(
            candidates,
            0,
            target,
            all_combs,
            curr_comb,
            0,
        )
        return all_combs


print(f"{Solution().combinationSum2([2,3,6,7],7)=}")
print(f"{Solution().combinationSum2([1,2],3)=}")
print(f"{Solution().combinationSum2([1,2],0)=}")
print(f"{Solution().combinationSum2([1,2],5)=}")
print(f"{Solution().combinationSum2([2,3,5],8)=}")

print(f"{Solution().combinationSum2([2,1,2],3)=}")
print(f"{Solution().combinationSum2([3,2,3,5],8)=}")
print(f"{Solution().combinationSum2([2,3,7,2],7)=}")

print(f"{Solution().combinationSum2([2,2],4)=}")
