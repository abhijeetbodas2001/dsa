from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        O(mn) time, O(1) extra space
        """
        rows = len(matrix)
        cols = len(matrix[0])
        row0_contains_zero = any(matrix[0][col] == 0 for col in range(0, cols))
        col0_contains_zero = any(matrix[row][0] == 0 for row in range(0, rows))

        for row in range(1, rows):
            for col in range(1, cols):
                if matrix[row][col] != 0:
                    continue

                # "mark" the rows and columns which should be set to zero
                matrix[row][0] = 0
                matrix[0][col] = 0

        # set rows and cols to zero
        for row in range(1, rows):
            if matrix[row][0] != 0:
                continue

            for col in range(1, cols):
                matrix[row][col] = 0

        for col in range(1, cols):
            if matrix[0][col] != 0:
                continue

            for row in range(1, rows):
                matrix[row][col] = 0

        # set first row and first col to zero if required
        if row0_contains_zero:
            for col in range(cols):
                matrix[0][col] = 0

        if col0_contains_zero:
            for row in range(rows):
                matrix[row][0] = 0
