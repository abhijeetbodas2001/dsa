import time
import itertools


def coordinates(loc: complex) -> tuple[int, int]:
    return int(loc.real), int(loc.imag)


def in_grid(grid, loc: complex) -> bool:
    rows, cols = len(grid), len(grid[0])
    return 0 <= loc.real < rows and 0 <= loc.imag < cols


rotation = -1j  # rotate 90 degree right => multiply by -1j


def walk(init_loc, init_direc, grid):
    visited: set[complex, complex] = set()
    loc, direc = init_loc, init_direc
    while True:
        assert (loc, direc) not in visited, "Loop detected!"
        visited.add((loc, direc))

        new_loc = loc + direc
        if not in_grid(grid, new_loc):
            break

        new_row, new_col = coordinates(new_loc)
        if grid[new_row][new_col] == "#":
            direc *= rotation
            continue

        loc = new_loc

    return visited


def solve():
    with open("./input.txt", "r") as f:
        grid = f.read().splitlines()
    grid = [[cell for cell in row] for row in grid]
    rows, cols = len(grid), len(grid[0])

    init_direc = -1 + 0j  # faces up => goes in direction of decreasing row index
    for row, col in itertools.product(range(rows), range(cols)):
        if grid[row][col] == "^":
            grid[row][col] = "."
            init_loc = complex(row, col)

    visited = walk(init_loc, init_direc, grid)

    print(f"Part 1: {len(set(v[0] for v in visited)) }")
    assert (init_loc, init_direc) in visited

    # Part 2: Brute force
    # Simulate what happens if obstacle is put after each point of the guard's path
    # TODO: Gives WA, need to debug

    print(time.time())
    new_obstacles: set[complex] = set()
    for loc, direc in visited:
        new_loc = loc + direc
        new_row, new_col = coordinates(new_loc)
        if not in_grid(grid, new_loc):
            continue
        if grid[new_row][new_col] == "#":
            continue
        if new_loc == init_loc:
            continue

        assert (new_loc, direc) in visited

        grid[new_row][new_col] = "#"
        try:
            # NOTE: start from the initial position, not (loc,direc)
            walk(init_loc, init_direc, grid)
        except AssertionError:
            new_obstacles.add(new_loc)
        grid[new_row][new_col] = "."

    print("Part 2:", len(new_obstacles))
    print(time.time())


if __name__ == "__main__":
    solve()
