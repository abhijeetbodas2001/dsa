def solve():
    n = int(input())

    if n == 1:
        print(1)
        return

    if n <= 3:
        print("NO SOLUTION")
        return

    permutation = [
        *[str(i) for i in range(1, n + 1) if i % 2 == 0],
        *[str(i) for i in range(1, n + 1) if i % 2 == 1],
    ]

    print(" ".join(permutation))


if __name__ == "__main__":
    solve()
