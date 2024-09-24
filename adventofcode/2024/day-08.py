from collections import defaultdict
import itertools


def solve():
    with open("./input.txt", "r") as f:
        grid = f.read().splitlines()

    grid = [[cell for cell in row] for row in grid]
    rows, cols = len(grid), len(grid[0])

    def in_grid(pos: complex) -> bool:
        return 0 <= pos.real < rows and 0 <= pos.imag < cols

    # Pre-computation
    char_locs = defaultdict(list)
    for row, col in itertools.product(range(rows), range(cols)):
        if grid[row][col] == ".":
            continue
        char_locs[grid[row][col]].append(complex(row, col))

    # Part 1
    antinodes: set[complex] = set()
    for char, locs in char_locs.items():
        for loc1, loc2 in itertools.combinations(locs, 2):
            antinodes.add(2 * loc1 - loc2)
            antinodes.add(2 * loc2 - loc1)

    antinodes = set(antinode for antinode in antinodes if in_grid(antinode))

    print("Part 1:", len(antinodes))

    # Part 2
    antinodes: set[complex] = set()
    for char, locs in char_locs.items():
        for loc1, loc2 in itertools.combinations(locs, 2):
            dir1, dir2 = loc1 - loc2, loc2 - loc1
            for loc, direc in itertools.product([loc1, loc2], [dir1, dir2]):
                antinode = loc + direc
                while in_grid(antinode):
                    antinodes.add(antinode)
                    antinode += direc

            antinodes.add(loc1)
            antinodes.add(loc2)

    print("Part 2:", len(antinodes))


if __name__ == "__main__":
    solve()
