def ans(n: int) -> int:
    if n == 1:
        return 0

    num_ways = (
        # Total number of ways to put 2 knights = n^2C2
        n**2 * (n**2 - 1) // 2
        # Number of ways to place knights so that thwy attack each other
        # Consider rectangles of size 3 x 2
        - 4 * (n - 1) * (n - 2)
    )

    return int(num_ways)


def solve():
    n = int(input())

    for i in range(1, n + 1):
        print(ans(i))


if __name__ == "__main__":
    solve()
