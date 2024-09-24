# %%
from typing import List


class Solution:
    def _get_shell(
        self, matrix, up: int, down: int, left: int, right: int
    ) -> List[int]:
        """
        Can this be changed to return an iterable?
        """
        if up > down or left > right:
            return []

        if up == down and left == right:
            return [matrix[up][left]]

        if up == down:
            return matrix[up][left : right + 1]

        if left == right:
            return [matrix[row][left] for row in range(up, down + 1)]

        shell = []
        shell.extend(matrix[up][col] for col in range(left, right + 1))
        shell.extend(matrix[row][right] for row in range(up + 1, down + 1))
        shell.extend(matrix[down][col] for col in range(right - 1, left - 1, -1))
        shell.extend(matrix[row][left] for row in range(down - 1, up, -1))

        return shell

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        up, down, left, right = 0, len(matrix) - 1, 0, len(matrix[0]) - 1
        while True:
            shell = self._get_shell(matrix, up, down, left, right)

            if len(shell) == 0:
                break

            res.extend(shell)
            up += 1
            down -= 1
            left += 1
            right -= 1

        return res
