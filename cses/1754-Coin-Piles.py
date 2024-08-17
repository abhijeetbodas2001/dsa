def solve_one():
    a, b = input().split(" ")
    a, b = int(a), int(b)

    a, b = max(a, b), min(a, b)
    if a > 2 * b:
        # Always remove 2 from the larger pile
        print("NO")
        return

    if int(b + a) % 3 != 0:
        # In every step, 3 is deducted from the total
        print("NO")
        return

    print("YES")


def solve():
    t = int(input())

    for _ in range(t):
        solve_one()


if __name__ == "__main__":
    solve()
