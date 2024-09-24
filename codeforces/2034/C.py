from collections import deque

# This is kinof like Pacific-Atlantic water flow
# https://leetcode.com/problems/pacific-atlantic-water-flow/description/


def inward_dir(curr_row, curr_col, neighbor_row, neighbor_col):
    if neighbor_row == curr_row + 1:
        return "U"
    if neighbor_row == curr_row - 1:
        return "D"
    if neighbor_col == curr_col + 1:
        return "L"
    if neighbor_col == curr_col - 1:
        return "R"

    raise AssertionError()


def solve():
    n, m = [int(x) for x in input().split()]
    grid = []
    for _ in range(n):
        grid.append([c for c in input()])

    # "good" => can get our of here
    is_good = [[False for _ in range(m)] for _ in range(n)]
    visited = [[False for _ in range(m)] for _ in range(n)]

    for row in range(n):
        for col in range(m):
            val = grid[row][col]
            if (
                (row == 0 and val == "U")
                or (row == n - 1 and val == "D")
                or (col == 0 and val == "L")
                or (col == m - 1 and val == "R")
            ):
                is_good[row][col] = True

    for row in range(n):
        for col in range(m):
            if not (row in [0, n - 1] or col in [0, m - 1]):
                continue

            if not is_good[row][col]:
                continue

            q = deque()
            q.append((row, col))

            while q:
                i, j = q.pop()
                if visited[i][j]:
                    continue

                visited[i][j] = True
                is_good[i][j] = True

                for ii, jj in ((i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)):
                    if not (0 <= ii < n and 0 <= jj < m):
                        continue
                    if not grid[ii][jj] == inward_dir(i, j, ii, jj):
                        continue

                    q.append((ii, jj))

    ans = 0
    for row in range(n):
        for col in range(m):
            if is_good[row][col]:
                continue

            # If all the cells around it are good, this cannot be bad
            if all(
                (
                    (0 <= i < n and 0 <= j < m) and is_good[i][j]
                )  # neighbor is inside the grid and is good
                or not (0 <= i < n and 0 <= j < m)  # neighbor is outide the grid
                for i, j in (
                    (row - 1, col),
                    (row + 1, col),
                    (row, col + 1),
                    (row, col - 1),
                )
            ):
                continue

            # If there are 2 or more bad/unknown cells in one island,
            # then the whole island is bad
            # island == graph component
            ans += 1

    print(ans)


if __name__ == "__main__":
    num_test_cases = int(input())
    # num_test_cases = 1
    for _ in range(num_test_cases):
        solve()
