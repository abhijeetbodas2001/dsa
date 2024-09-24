#%%
from typing import List


class Solution:
    def _rotate_shell(self, matrix: List[List[int]], m: int) -> None:
        """
        for outer shell:
        0, x -> x, m-1
        x, m-1 -> m-1, m-1-x
        m-1, m-1-x -> m-1-x, 0
        m-1-x, 0 -> 0, x
        """

        if m == 1 or m == 0:
            return

        n = len(matrix)
        diff = (n-m)//2

        for idx in range(0, m-1):
            tmp = matrix[0+diff][idx+diff]
            matrix[diff][idx+diff] = matrix[m-1-idx+diff][0+diff]
            matrix[m-1-idx+diff][0+diff] = matrix[m-1+diff][m-1-idx+diff]
            matrix[m-1+diff][m-1-idx+diff] = matrix[idx+diff][m-1+diff]
            matrix[idx+diff][m-1+diff] = tmp

    def rotate(self, matrix: List[List[int]]) -> None:
        for idx in range(len(matrix), 0, -2):
            self._rotate_shell(matrix, idx)