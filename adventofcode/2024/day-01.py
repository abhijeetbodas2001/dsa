from collections import Counter


def solve():
    arr1, arr2 = [], []
    with open("./input.txt", "r") as f:
        for line in f.readlines():
            a, b = [int(x) for x in line.split()]
            arr1.append(a)
            arr2.append(b)

    arr1.sort()
    arr2.sort()

    print("Part 1:", sum(abs(x - y) for x, y in zip(arr1, arr2)))

    counts = Counter(arr2)
    ans = sum(a * counts[a] for a in arr1)

    print("Part 2:", ans)


if __name__ == "__main__":
    solve()
