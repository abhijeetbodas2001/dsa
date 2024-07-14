from itertools import chain


def solve():
    n = int(input())

    if n % 4 != 0 and (n + 1) % 4 != 0:
        print("NO")
        return

    print("YES")

    x = n if n % 4 == 0 else n + 1

    group1 = set(chain.from_iterable((i, x + 1 - i) for i in range(1, x // 2 + 1, 2)))
    group2 = set(chain.from_iterable((i, x + 1 - i) for i in range(2, x // 2 + 1, 2)))

    if x != n:
        group1.remove(x)
        group1.add(x // 2)
        group2.remove(x // 2)

    group1 = [str(i) for i in group1]
    group2 = [str(i) for i in group2]

    print(len(group1))
    print(" ".join(group1))
    print(len(group2))
    print(" ".join(group2))


if __name__ == "__main__":
    solve()
