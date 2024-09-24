from collections import deque
from typing import List, Set, Tuple

Cell = Tuple[int, int]


class Solution:
    def _dfs(
        self,
        heights: List[List[int]],
        start: Cell,
        visited: Set[Cell],
    ):
        """
        Do BFS starting at `start`, considering only cells from which water can
        flow into `start` cell

        Modify `visited` in place
        """

        stack = deque()
        stack.append(start)

        rows, cols = len(heights), len(heights[0])

        while len(stack) > 0:
            parent = stack.pop()
            if parent in visited:
                continue

            parent_row, parent_col = parent
            for row, col in [
                (parent_row + 1, parent_col),
                (parent_row - 1, parent_col),
                (parent_row, parent_col - 1),
                (parent_row, parent_col + 1),
            ]:
                if row < 0 or row >= rows or col < 0 or col >= cols:
                    continue

                if heights[row][col] < heights[parent_row][parent_col]:
                    # Only add cells which are reachable into the visited set
                    continue

                if (row, col) not in visited:
                    stack.append((row, col))

            visited.add(parent)

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows = len(heights)
        cols = len(heights[0])

        # Process top and left edges
        pacific_visited: Set[Cell] = set()
        for col in range(cols):
            row = 0
            self._dfs(heights, (row, col), pacific_visited)

        for row in range(rows):
            col = 0
            self._dfs(heights, (row, col), pacific_visited)
        # Now, pacific_visited contains all cells from which water can
        # flow into pacific

        # Process bottom and right edges
        atlantic_visited: Set[Cell] = set()
        for col in range(cols):
            row = rows - 1
            self._dfs(heights, (row, col), atlantic_visited)

        for row in range(rows):
            col = cols - 1
            self._dfs(heights, (row, col), atlantic_visited)
        # Now, atlantic_visited contains all cells from which water can
        # flow into atlantic

        # Convert set[tuple] to list[list]
        return list(
            list(cell) for cell in pacific_visited.intersection(atlantic_visited)
        )
