def solve():
    with open("./input.txt", "r") as f:
        s = f.read().splitlines()[0]

    expanded = []
    block_num = 0
    for idx, num in enumerate(s):
        num = int(num)
        if idx % 2:
            expanded.extend(["."] * num)
        else:
            expanded.extend([str(block_num)] * num)
            block_num += 1

    n = len(expanded)
    left, right = 0, n - 1
    while expanded[left] != ".":
        left += 1

    while left < right:
        expanded[left], expanded[right] = expanded[right], expanded[left]
        while expanded[left] != ".":
            left += 1
        while expanded[right] == ".":
            right -= 1

    total = 0
    for idx, num in enumerate(expanded):
        if num == ".":
            continue
        total += idx * int(num)

    print("Part 1:", total)

    # Part 2
    # for each free block, store size and start index (in expanded)
    frees: list[list[int, int]] = []
    expanded = []
    offsets: list[int] = []  # for each index in s, store start index in expanded
    block_num = 0
    for idx, num in enumerate(s):
        num = int(num)
        offsets.append(len(expanded))
        if idx % 2:
            frees.append([num, len(expanded)])
            expanded.extend(["."] * num)
        else:
            expanded.extend([str(block_num)] * num)
            block_num += 1

    for s_index in range(len(s) - 1, -1, -2):
        file_size = int(s[s_index])
        orig_pos = offsets[s_index]
        for block in frees:
            if block[0] < file_size:
                continue
            if block[1] >= orig_pos:
                break
            block[0] -= file_size
            for idx in range(file_size):
                expanded[block[1] + idx], expanded[orig_pos + idx] = (
                    expanded[orig_pos + idx],
                    expanded[block[1] + idx],
                )
            block[1] = block[1] + file_size
            break
        # print("".join(expanded))

    # print(offsets)
    # print(frees)

    total = 0
    for idx, num in enumerate(expanded):
        if num == ".":
            continue
        total += idx * int(num)

    print("Part 2:", total)


if __name__ == "__main__":
    solve()
