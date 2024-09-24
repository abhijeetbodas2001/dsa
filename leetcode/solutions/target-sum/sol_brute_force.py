# Brute force solution, gives TLE
class Solution:
    def _generate_combinations(
        self, nums: list[int], target: int, curr_comb: list[int]
    ) -> None:
        if len(curr_comb) == len(nums):
            tot = 0
            for sign, num in zip(curr_comb, nums):
                if sign == "+":
                    tot += num
                else:
                    tot -= num

            if tot == target:
                self.ans += 1
            return

        curr_comb.append("+")
        self._generate_combinations(nums, target, curr_comb)
        curr_comb.pop()

        curr_comb.append("-")
        self._generate_combinations(nums, target, curr_comb)
        curr_comb.pop()

    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        curr_comb = []
        self.ans = 0
        self._generate_combinations(nums, target, curr_comb)

        return self.ans


print(f"{Solution().findTargetSumWays([1,1,1,1,1],3)=}")
print(f"{Solution().findTargetSumWays([1,2,3],2)=}")
print(f"{Solution().findTargetSumWays([1,2,3],0)=}")
print(f"{Solution().findTargetSumWays([1,2,3],6)=}")
print(f"{Solution().findTargetSumWays([1,2,3],-2)=}")
print(f"{Solution().findTargetSumWays([1,2,3],10)=}")
