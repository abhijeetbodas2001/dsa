from typing import List


class Solution:
    def _generate_permutations(self, s: str, prefix: str, perms: List[str]) -> None:
        if len(prefix) == len(s):
            perms.append(prefix)
            return

        next_char = s[len(prefix)]

        # NOTE: this is a set, because lower and upper can be the same
        # for digits etc
        for char in {
            next_char.lower(),
            next_char.upper(),
        }:
            self._generate_permutations(s, prefix + char, perms)

    def letterCasePermutation(self, s: str) -> List[str]:
        if not s:
            return []

        ans: List[str] = []
        s = s.lower()

        self._generate_permutations(s, "", ans)
        return ans


assert set(Solution().letterCasePermutation("ab")) == set(["aB", "Ab", "ab", "AB"])
assert Solution().letterCasePermutation("") == []
assert set(Solution().letterCasePermutation("a")) == set(["a", "A"])
