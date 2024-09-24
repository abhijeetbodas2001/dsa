# See neetcode: https://www.youtube.com/watch?v=s9fokUqJ76A
# Instead of creating stack and checking at each leaf, do not get inside
# sub-trees which are for sure un-balanced
from typing import List
from collections import deque


class Solution:
    def _generate_parenthesis(
        self,
        n: int,
        all_combs: List[List[int]],
        curr_comb: List[int],
        opening: int,
        closing: int,
    ):
        if n == 0:
            if opening == closing:
                all_combs.append(curr_comb.copy())
            return

        # More pruning can be done, ex: if opening == n, do add opening again
        curr_comb.append("(")
        self._generate_parenthesis(n - 1, all_combs, curr_comb, opening + 1, closing)
        curr_comb.pop()

        if closing < opening:
            curr_comb.append(")")
            self._generate_parenthesis(
                n - 1, all_combs, curr_comb, opening, closing + 1
            )
            curr_comb.pop()

    def generateParenthesis(self, n: int) -> List[str]:
        stack = deque()
        all_combs = []
        curr_comb = []

        self._generate_parenthesis(2 * n, all_combs, curr_comb, 0, 0)
        return ["".join(x) for x in all_combs]


print(Solution().generateParenthesis(1))
print(Solution().generateParenthesis(4))
