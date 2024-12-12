import itertools
from collections import deque


def solve():
    with open("./input.txt", "r") as f:
        grid = f.read().splitlines()

    grid = [[x for x in row] for row in grid]
    rows, cols = len(grid), len(grid[0])

    def in_grid(row, col) -> bool:
        return 0 <= row < rows and 0 <= col < cols

    def nbrs(row, col):
        return [[row + 1, col], [row - 1, col], [row, col + 1], [row, col - 1]]

    def num_boundaries(row, col) -> int:
        b = 0
        for r, c in nbrs(row, col):
            if not in_grid(r, c) or grid[row][col] != grid[r][c]:
                b += 1

        return b

    visited = [[False for _ in row] for row in grid]

    cost: dict[str, int] = {}  # map from letter to cost

    def dfs(row: int, col: int):
        if visited[row][col]:
            return set()

        component: set[tuple[int, int]] = set()
        stack = deque()
        stack.append((row, col))
        while stack:
            r, c = stack.pop()
            component.add((r, c))
            visited[r][c] = True

            for cr, cc in nbrs(r, c):
                if not in_grid(cr, cc):
                    continue

                if grid[cr][cc] != grid[r][c]:
                    continue

                if visited[cr][cc]:
                    continue

                stack.append((cr, cc))
        return component

    cost = 0

    for row, col in itertools.product(range(rows), range(cols)):
        component = dfs(row, col)
        area, perimeter = 0, 0
        for cell in component:
            area += 1
            perimeter += num_boundaries(*cell)
        cost += area * perimeter

    print("Part 1:", cost)


if __name__ == "__main__":
    solve()
