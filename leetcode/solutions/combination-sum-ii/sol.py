from typing import List


class Solution:
    def _generate_combinations(
        self,
        uniq_candidates: List[int],
        counts: dict[int, int],
        start_idx: int,  # index in uniq_candidates to consider for appending to curr_comb
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

        for idx in range(start_idx, len(uniq_candidates)):
            num = uniq_candidates[idx]
            if counts[num] == 0:
                continue

            counts[num] -= 1
            curr_comb.append(num)
            self._generate_combinations(
                uniq_candidates,
                counts,
                idx,  # do not increment the idx, because duplicates are allowed (count checking will be done in the next recursive call)
                target,
                all_combs,
                curr_comb,
                curr_sum + num,
            )
            curr_comb.pop()
            counts[num] += 1

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        counts = {}
        for candidate in candidates:
            counts[candidate] = counts.get(candidate, 0) + 1
        uniq_candidates = sorted(counts.keys())

        all_combs = []
        curr_comb = []

        self._generate_combinations(
            uniq_candidates,
            counts,
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
