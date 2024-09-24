import itertools
import re


def solve():
    with open("./test.txt", "r") as f:
        lines = f.read().splitlines()

    grid = [[x for x in line] for line in lines]

    # one row as one string
    rows = ["".join(row) for row in grid]
    # one col as one string
    cols = ["".join(col) for col in zip(*grid)]

    total = 0

    # horizontal and vertical occurences
    for line in itertools.chain(rows, cols):
        total += len(re.findall(r"XMAS", line))
        total += len(re.findall(r"SAMX", line))

    # NW to SE
    for xrow, xcol in itertools.product(range(len(rows)), range(len(cols))):
        if xrow + 3 >= len(rows) or xcol + 3 >= len(cols):
            continue

        s = "".join(grid[xrow + i][xcol + i] for i in range(4))
        if s == "XMAS":
            total += 1
        if s == "SAMX":
            total += 1

    # NE to SW
    for xrow, xcol in itertools.product(range(len(rows)), range(len(cols))):
        if xrow + 3 >= len(rows) or xcol - 3 < 0:
            continue

        s = "".join(grid[xrow + i][xcol - i] for i in range(4))
        if s == "XMAS":
            total += 1
        if s == "SAMX":
            total += 1

    print("Part 1:", total)

    total = 0
    words = ["MAS", "SAM"]
    # Check each cell if it can be the mid point of the "X"
    for arow, acol in itertools.product(range(len(rows)), range(len(cols))):
        if (
            arow - 1 < 0
            or acol - 1 < 0
            or arow + 1 >= len(rows)
            or acol + 1 >= len(cols)
        ):
            continue

        diag1 = "".join(
            [grid[arow - 1][acol - 1], grid[arow][acol], grid[arow + 1][acol + 1]]
        )
        diag2 = "".join(
            [grid[arow - 1][acol + 1], grid[arow][acol], grid[arow + 1][acol - 1]]
        )

        if diag1 in words and diag2 in words:
            total += 1

    print("Part 2:", total)


if __name__ == "__main__":
    solve()

