def is_safe(level: list[int]) -> bool:
    # Brute force
    diffs = [level[i + 1] - level[i] for i in range(len(level) - 1)]
    return (min(diffs) > 0 and max(diffs) <= 3) or (max(diffs) < 0 and min(diffs) >= -3)


def solve():
    safe = 0
    with open("./input.txt", "r") as f:
        lines = f.read().splitlines()

    for line in lines:
        level = [int(x) for x in line.split()]
        diffs = [level[i + 1] - level[i] for i in range(len(level) - 1)]
        if (min(diffs) > 0 and max(diffs) <= 3) or (
            max(diffs) < 0 and min(diffs) >= -3
        ):
            safe += 1

    print("Part 1:", safe)

    safe = 0
    for line in lines:
        level = [int(x) for x in line.split()]
        if is_safe(level):
            safe += 1
            continue

        for idx in range(len(level)):
            if is_safe(level[:idx] + level[idx + 1 :]):
                safe += 1
                break

    print("Part 2:", safe)


if __name__ == "__main__":
    solve()
