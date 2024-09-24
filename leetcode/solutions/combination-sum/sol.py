from typing import List


class Solution:
    def _generate_combinations(
        self,
        candidates: List[int],
        target: int,
        curr_sum: int,
        curr_comb: List[int],
        all_combs: List[List[int]],
        start_idx: int,
    ) -> None:
        if curr_sum > target:
            return

        if curr_sum == target:
            all_combs.append(curr_comb.copy())
            return

        # NOTE: in this problem, duplicates numbers from the candidates list
        # are allowed to be chosen (ie, one number can be chosen multiple times),
        # but the same combination cannot with different orders of numbers is
        # not allowed
        # Ex: [1,2,2] and [2,1,2] both cannot be in the final answer
        # This means, in the next recursive call, we are allowed to select the
        # number we selected just now (which will allow 2 2's), but we cannot
        # select any number which occured prior to the number we just chose
        # (doing so will give the array [2,1,2], assuming candidates=[1,2]
        # So, the slice here is from start_idx, which denotes the numebr
        # which was chosen in the last recursive call.
        # This works because candidates are unique
        for idx in range(start_idx, len(candidates)):
            # select this num
            num = candidates[idx]
            curr_comb.append(num)
            self._generate_combinations(
                candidates,
                target,
                curr_sum + num,
                curr_comb,
                all_combs,
                idx,
            )
            curr_comb.pop()

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        # Given, candidates are unique
        assert len(candidates) == len(set(candidates))

        if not candidates:
            return []

        all_combs = []
        curr_comb = []
        curr_sum = 0

        self._generate_combinations(
            candidates, target, curr_sum, curr_comb, all_combs, 0
        )
        return all_combs


print(f"{Solution().combinationSum([2,3,6,7],7)=}")
print(f"{Solution().combinationSum([1,2],3)=}")
print(f"{Solution().combinationSum([1,2],0)=}")
print(f"{Solution().combinationSum([1,2],5)=}")
print(f"{Solution().combinationSum([2,3,5],8)=}")
