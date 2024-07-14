def solve():
    s = input() + "#"

    count = 1
    count_max = 0
    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            count = count + 1
            continue

        count_max = max(count_max, count)
        count = 1

    print(count_max)


if __name__ == "__main__":
    solve()
