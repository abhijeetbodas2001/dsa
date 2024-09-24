from typing import List, Dict


class Solution:
    def _generate_permutations(
        self,
        available_nums: Dict[int, int],
        current_perm: List[int],
        all_perms: List[List[int]],
        perms_len: int,
    ) -> None:
        if len(current_perm) == perms_len:
            all_perms.append(current_perm)
            return

        for num, count in available_nums.items():
            if count == 0:
                continue

            # do not modify current_perm in place!
            extended_perm = current_perm + [num]
            available_nums[num] -= 1
            self._generate_permutations(
                available_nums, extended_perm, all_perms, perms_len
            )
            available_nums[num] += 1

    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        # since it is given that max(nums) <= 10, this could have been a
        # fixed size array, and that would be faster and use lesser memory
        available_nums: Dict[int, int] = {}
        for num in nums:
            available_nums[num] = available_nums.get(num, 0) + 1

        all_perms = []
        self._generate_permutations(available_nums, [], all_perms, len(nums))

        return all_perms


assert Solution().permuteUnique([]) == [[]], Solution().permuteUnique([])
assert Solution().permuteUnique([1]) == [[1]], Solution().permuteUnique([1])
assert Solution().permuteUnique([1, 2]) == [[1, 2], [2, 1]], Solution().permuteUnique(
    [1, 2]
)

print(f"{Solution().permuteUnique([1,1,2])=}")
print(f"{Solution().permuteUnique([1,1,2,2])=}")
print(f"{Solution().permuteUnique([1,2,1,2])=}")
