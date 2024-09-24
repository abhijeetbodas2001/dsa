from collections import deque
from typing import List, Set, Tuple

Cell = Tuple[int, int]


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rows = len(grid)
        cols = len(grid[0])

        visited: Set[Cell] = set()
        num_islands = 0

        for row in range(rows):
            for col in range(cols):
                cell = (row, col)

                if cell in visited or grid[row][col] == "0":
                    # one iteration of this loop adds cells in one island to
                    # the visited set
                    continue

                num_islands += 1

                # do dfs
                stack = deque()
                stack.append(cell)

                while len(stack) > 0:
                    parent_cell = stack.pop()
                    visited.add(parent_cell)
                    parent_row, parent_col = parent_cell

                    for child_row, child_col in [
                        (parent_row + 1, parent_col),
                        (parent_row - 1, parent_col),
                        (parent_row, parent_col + 1),
                        (parent_row, parent_col - 1),
                    ]:
                        if (
                            child_row < 0
                            or child_row >= rows
                            or child_col < 0
                            or child_col >= cols
                        ):
                            continue

                        if grid[child_row][child_col] == "0":
                            continue

                        if (child_row, child_col) in visited:
                            continue

                        stack.append((child_row, child_col))

        return num_islands
