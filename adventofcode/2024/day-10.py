from pprint import pprint as print
from collections import defaultdict


Point = tuple[int, int]


def solve():
    with open("./input.txt", "r") as f:
        grid = f.read().splitlines()

    grid = [[char for char in row] for row in grid]
    rows, cols = len(grid), len(grid[0])

    trailheads: set[Point] = set()
    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == "0":
                trailheads.add((row, col))

    # maps each trailhead to nines
    accessible_nines: dict[Point, set[Point]] = defaultdict(set)
    new_rating: dict[Point, int] = {}

    def recurse(trailhead: Point, loc: Point, visited: set[Point]):
        visited.add(loc)
        if grid[loc[0]][loc[1]] == "9":
            accessible_nines[trailhead].add(loc)
            new_rating[trailhead] = new_rating.get(trailhead, 0) + 1
            return

        row, col = loc
        for child_row, child_col in [
            [row + 1, col],
            [row - 1, col],
            [row, col + 1],
            [row, col - 1],
        ]:
            if not (0 <= child_row < rows and 0 <= child_col < cols):
                continue

            # if (child_row, child_col) in visited:
            #     continue

            if int(grid[row][col]) + 1 != int(grid[child_row][child_col]):
                continue

            recurse(trailhead, (child_row, child_col), visited)

    for trailhead in trailheads:
        recurse(trailhead, trailhead, set())

    print(sum(len(nines) for nines in accessible_nines.values()))
    print(new_rating)
    print(sum(rat for rat in new_rating.values()))


if __name__ == "__main__":
    solve()
