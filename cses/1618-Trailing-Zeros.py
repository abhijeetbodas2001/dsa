def solve():
    n = int(input())

    ans = 0
    pow5 = 1
    while pow5 < 10**9:
        pow5 = int(pow5 * 5)

    while pow5 > 1:
        ans = ans + n // pow5
        pow5 = pow5 // 5

    print(ans)


if __name__ == "__main__":
    solve()
