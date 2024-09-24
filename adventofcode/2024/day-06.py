import itertools


def solve():
    with open("./test.txt", "r") as f:
        grid = f.read().splitlines()
    grid = [[cell for cell in row] for row in grid]
    rows, cols = len(grid), len(grid[0])

    def in_grid(pos: complex) -> bool:
        return 0 <= pos.real < rows and 0 <= pos.imag < cols

    def coordinates(pos: complex) -> tuple[int, int]:
        return int(pos.real), int(pos.imag)

    init_direc = -1 + 0j  # faces up => goes in direction of decreasing row index
    for row, col in itertools.product(range(rows), range(cols)):
        if grid[row][col] == "^":
            init_pos = complex(row, col)

    # Store location and direction for the guard
    visited: set[tuple[complex, complex]] = set()
    loc = init_pos
    direc = init_direc
    rotation = -1j  # rotate 90 degree right => multiply by -1j

    while True:
        assert (loc, direc) not in visited, "Loop detected in Part 1!"
        visited.add((loc, direc))

        new_loc = loc + direc
        if not in_grid(new_loc):
            break

        new_row, new_col = coordinates(new_loc)
        if grid[new_row][new_col] == "#":
            direc *= rotation
            continue

        loc = new_loc

    print(f"Part 1: {len(set(v[0] for v in visited)) }")
    assert (init_pos, init_direc) in visited

    # Part 2: Brute force
    # Simulate what happens if obstacle is put after each point of the guard's path
    # TODO: Gives WA, need to debug
    new_obstacles: set[complex] = set()
    for loc, direc in visited:
        new_obstacle = loc + direc
        obs_row, obs_col = coordinates(new_obstacle)
        if (
            not in_grid(new_obstacle)
            or new_obstacle == init_pos
            or grid[obs_row][obs_col] == "#"
        ):
            continue

        grid[obs_row][obs_col] = "#"
        visited_local: set[tuple[complex, complex]] = set()
        curr_direc = direc * rotation
        curr_loc = loc

        while True:
            if (curr_loc, curr_direc) in visited_local:
                # loop detected
                new_obstacles.add(new_obstacle)
                break
            visited_local.add((curr_loc, curr_direc))

            new_loc = curr_loc + curr_direc
            new_row, new_col = int(new_loc.real), int(new_loc.imag)

            if not in_grid(new_loc):
                break

            if grid[new_row][new_col] == "#":
                curr_direc *= rotation
                continue

            curr_loc = new_loc

        grid[obs_row][obs_col] = "."  # Cleanup

    print(new_obstacles)
    print(f"Part 2: {len(new_obstacles)}")

    # Part 2 can be optimised
    # obstacles = set(
    #     complex(row, col)
    #     for row, col in itertools.product(range(rows), range(cols))
    #     if grid[row][col] == "#"
    # )
    # obstacles_in_row = [
    #     [col for col in range(cols) if grid[row][col] == "#"] for row in range(rows)
    # ]
    # obstacles_in_col = [
    #     [row for row in range(rows) if grid[row][col] == "#"] for col in range(cols)
    # ]

    # print(f"{len(obstacles)=}")  # 848
    # print(f"{max(rows,cols)=}")  # 130
    # length of path is 4374

    # Only possible location of obstacle will be points which lie on the path of the
    # guard already
    # For each such path, simulate what happens on putting an obstacle at the point
    # next to the current location of the guard.
    # In such a simulation, in the worst case, the guard will bounce of all the existing
    # obstacles plus one. Finding each obstacle when we are at some obstacle will
    # take log(max(rows, cols)) time in the worst case (do binary search over the
    # obstacle array).
    # There will be 4374 such simulations, each taking 848*log(130) operations.
    # In total there will be close to one million operations, which should be fast.


if __name__ == "__main__":
    solve()
