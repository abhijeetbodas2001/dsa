class Solution:
    def _generate_combs(
        self, digits: str, curr_comb: list[str], all_combs: list[str], start: int
    ) -> None:
        if len(digits) == len(curr_comb):
            all_combs.append("".join(curr_comb))
            return

        # select one chat from each digit
        for idx in range(start, len(digits)):
            for char in self.num_map[int(digits[idx])]:
                curr_comb.append(char)
                self._generate_combs(digits, curr_comb, all_combs, idx + 1)
                curr_comb.pop()

    def letterCombinations(self, digits: str) -> list[str]:
        if not digits:
            return []

        self.num_map = [
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        ]

        all_combs = []
        curr_comb = []
        self._generate_combs(digits, curr_comb, all_combs, 0)
        return all_combs


answers = [
    Solution().letterCombinations("25"),
    Solution().letterCombinations("782"),
    Solution().letterCombinations(""),
]

for ans in answers:
    print(ans)
