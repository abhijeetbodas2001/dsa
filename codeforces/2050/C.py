def recurse(arr: list[list[int]], start: int, curr_sum: int) -> bool:
    if start == len(arr):
        return curr_sum % 9 == 0

    for idx in range(start, len(arr)):
        assert l in [1, 2]
        if l == 1:
            return recurse(arr, idx + 1, curr_sum + arr[idx][0])
        else:
            return recurse(arr, idx + 1, curr_sum + arr[idx][0]) or recurse(
                arr, idx + 1, curr_sum + arr[idx][1]
            )


def solve_slow():
    """
    Brute force, gives TLE
    """
    arr = [[int(x)] for x in input()]
    for idx in range(len(arr)):
        if arr[idx][0] in [2, 3]:
            sq = arr[idx][0] ** 2
            arr[idx].append(sq)

    if recurse(arr, 0, 0):
        print("yes")
    else:
        print("no")


def solve():
    """
    Fast solution, with dp
    """
    arr = [[int(x)] for x in input()]
    n = len(arr)
    for idx in range(n):
        if arr[idx][0] in [2, 3]:
            sq = arr[idx][0] ** 2
            arr[idx].append(sq)

    # dp[i][j] = True if we can get a sum of digits with remainder j (mod 9), by utilizing digits from i onwards
    # base case
    dp = [[False for _ in range(9)] for _ in range(n)]
    for num in arr[n - 1]:
        dp[n - 1][num % 9] = True

    for idx in range(n - 2, -1, -1):
        for num in arr[idx]:
            for rem in range(9):
                if dp[idx + 1][rem]:
                    dp[idx][(rem + num) % 9] = True

    print("yes" if dp[0][0] else "no")


if __name__ == "__main__":
    num_test_cases = int(input())
    # num_test_cases = 1
    for _ in range(num_test_cases):
        solve()
