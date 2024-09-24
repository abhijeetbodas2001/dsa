def solve():
    n = int(input())

    if n <= 2:
        print(n)
        return

    if n in [3, 4]:
        print(2)
        return

    start = 4
    ans = 2
    while start < n:
        ans += 1
        start = start * 2 + 2

    print(ans)


if __name__ == "__main__":
    num_test_cases = int(input())
    # num_test_cases = 1
    for _ in range(num_test_cases):
        solve()
