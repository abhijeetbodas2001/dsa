from typing import List
from collections import deque


class Solution:
    def _generate_parenthesis(self, n, all_combs, curr_comb):
        if n == 0:
            stack = deque()
            for x in curr_comb:
                if x == "(":
                    stack.append(x)
                else:
                    if stack and stack[-1] == "(":
                        stack.pop()
                    else:
                        stack.append(x)

            if not stack:
                all_combs.append(curr_comb.copy())
            return

        curr_comb.append("(")
        self._generate_parenthesis(n - 1, all_combs, curr_comb)
        curr_comb.pop()

        curr_comb.append(")")
        self._generate_parenthesis(n - 1, all_combs, curr_comb)
        curr_comb.pop()

    def generateParenthesis(self, n: int) -> List[str]:
        stack = deque()
        all_combs = []
        curr_comb = []

        self._generate_parenthesis(2 * n, all_combs, curr_comb)
        return ["".join(x) for x in all_combs]


print(Solution().generateParenthesis(1))
print(Solution().generateParenthesis(3))
