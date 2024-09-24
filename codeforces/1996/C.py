def solve_one():
    n, q = input().split(" ")
    n, q = int(n), int(q)

    a = input()
    b = input()

    counters_a = [[0] * 26]
    counters_b = [[0] * 26]
    for i in range(1, n + 1):
        x = list(counters_a[i - 1])
        x[ord(a[i - 1]) - ord("a")] += 1
        counters_a.append(x)

        x = list(counters_b[i - 1])
        x[ord(b[i - 1]) - ord("a")] += 1
        counters_b.append(x)

    for i in range(q):
        l, r = input().split(" ")
        l, r = int(l) - 1, int(r) - 1

        diff = sum(
            abs(
                (counters_a[r + 1][k] - counters_a[l][k])
                - (counters_b[r + 1][k] - counters_b[l][k])
            )
            for k in range(26)
        )

        print(diff // 2)


def solve():
    t = int(input())
    for _ in range(t):
        solve_one()


if __name__ == "__main__":
    solve()
