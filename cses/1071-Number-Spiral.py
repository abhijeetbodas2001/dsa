def solve_one():
    row, col = [int(i) for i in input().split(" ")]

    max_row_col = max([row, col])
    inner_shell = (max_row_col - 1) ** 2
    start_from_down_right = (max_row_col - 1) % 2 == 0
    outer_shell = max_row_col**2

    if start_from_down_right and row < col:
        ans = outer_shell - (row - 1)
    elif start_from_down_right and row >= col:
        ans = inner_shell + col
    elif not start_from_down_right and row < col:
        ans = inner_shell + row
    elif not start_from_down_right and row >= col:
        ans = outer_shell - (col - 1)
    else:
        raise AssertionError()

    print(ans)


def solve():
    t = int(input())

    for _ in range(t):
        solve_one()


if __name__ == "__main__":
    solve()
