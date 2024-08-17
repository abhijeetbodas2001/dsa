def solve():
    n = int(input())
    MOD = int(10**9 + 7)

    ans = 1
    for _ in range(n):
        ans = (ans * 2) % MOD

    print(ans)


if __name__ == "__main__":
    solve()
